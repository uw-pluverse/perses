
































use core::cmp::Ordering;
use core::marker::PhantomData;
use core::mem::{self, MaybeUninit};
use core::ptr::{self, NonNull, Unique};
use core::slice;

use crate::alloc::{AllocRef, Global, Layout};
use crate::boxed::Box;

const B: usize = 6;
pub const MIN_LEN: usize = B - 1;
pub const CAPACITY: usize = 2 * B - 1;
const KV_IDX_CENTER: usize = B - 1;
const EDGE_IDX_LEFT_OF_CENTER: usize = B - 1;
const EDGE_IDX_RIGHT_OF_CENTER: usize = B;


struct LeafNode<K, V> {

    parent: Option<NonNull<InternalNode<K, V>>>,




    parent_idx: MaybeUninit<u16>,


    len: u16,



    keys: [MaybeUninit<K>; CAPACITY],
    vals: [MaybeUninit<V>; CAPACITY],
}

impl<K, V> LeafNode<K, V> {


    unsafe fn new() -> Self {
        LeafNode {


            keys: MaybeUninit::uninit_array(),
            vals: MaybeUninit::uninit_array(),
            parent: None,
            parent_idx: MaybeUninit::uninit(),
            len: 0,
        }
    }
}






#[repr(C)]

struct InternalNode<K, V> {

    data: LeafNode<K, V>,




    edges: [MaybeUninit<BoxedNode<K, V>>; 2 * B],
}

impl<K, V> InternalNode<K, V> {







    unsafe fn new() -> Self {
        InternalNode { data: unsafe { LeafNode::new() }, edges: MaybeUninit::uninit_array() }
    }
}







struct BoxedNode<K, V> {
    ptr: Unique<LeafNode<K, V>>,
}

impl<K, V> BoxedNode<K, V> {
    fn from_leaf(node: Box<LeafNode<K, V>>) -> Self {
        BoxedNode { ptr: Box::into_unique(node) }
    }

    fn from_internal(node: Box<InternalNode<K, V>>) -> Self {
        BoxedNode { ptr: Unique::from(&mut Box::leak(node).data) }
    }

    unsafe fn from_ptr(ptr: NonNull<LeafNode<K, V>>) -> Self {
        BoxedNode { ptr: unsafe { Unique::new_unchecked(ptr.as_ptr()) } }
    }

    fn as_ptr(&self) -> NonNull<LeafNode<K, V>> {
        NonNull::from(self.ptr)
    }
}




pub struct Root<K, V> {
    node: BoxedNode<K, V>,

    height: usize,
}

unsafe impl<K: Sync, V: Sync> Sync for Root<K, V> {}
unsafe impl<K: Send, V: Send> Send for Root<K, V> {}

impl<K, V> Root<K, V> {

    pub fn height(&self) -> usize {
        self.height
    }


    pub fn new_leaf() -> Self {
        Root { node: BoxedNode::from_leaf(Box::new(unsafe { LeafNode::new() })), height: 0 }
    }


    pub fn node_as_ref(&self) -> NodeRef<marker::Immut<'_>, K, V, marker::LeafOrInternal> {
        NodeRef { height: self.height, node: self.node.as_ptr(), _marker: PhantomData }
    }


    pub fn node_as_mut(&mut self) -> NodeRef<marker::Mut<'_>, K, V, marker::LeafOrInternal> {
        NodeRef { height: self.height, node: self.node.as_ptr(), _marker: PhantomData }
    }

    pub fn node_as_valmut(&mut self) -> NodeRef<marker::ValMut<'_>, K, V, marker::LeafOrInternal> {
        NodeRef { height: self.height, node: self.node.as_ptr(), _marker: PhantomData }
    }

    pub fn into_ref(self) -> NodeRef<marker::Owned, K, V, marker::LeafOrInternal> {
        NodeRef { height: self.height, node: self.node.as_ptr(), _marker: PhantomData }
    }




    pub fn push_internal_level(&mut self) -> NodeRef<marker::Mut<'_>, K, V, marker::Internal> {
        let mut new_node = Box::new(unsafe { InternalNode::new() });
        new_node.edges[0].write(unsafe { BoxedNode::from_ptr(self.node.as_ptr()) });

        self.node = BoxedNode::from_internal(new_node);
        self.height += 1;

        let mut ret =
            NodeRef { height: self.height, node: self.node.as_ptr(), _marker: PhantomData };

        unsafe {
            ret.reborrow_mut().first_edge().correct_parent_link();
        }

        ret
    }










    pub fn pop_internal_level(&mut self) {
        assert!(self.height > 0);

        let top = self.node.ptr;

        self.node = unsafe {
            BoxedNode::from_ptr(
                self.node_as_mut().cast_unchecked::<marker::Internal>().first_edge().descend().node,
            )
        };
        self.height -= 1;
        self.node_as_mut().as_leaf_mut().parent = None;

        unsafe {
            Global.dealloc(NonNull::from(top).cast(), Layout::new::<InternalNode<K, V>>());
        }
    }
}





















pub struct NodeRef<BorrowType, K, V, Type> {

    height: usize,
    node: NonNull<LeafNode<K, V>>,
    _marker: PhantomData<(BorrowType, Type)>,
}

impl<'a, K: 'a, V: 'a, Type> Copy for NodeRef<marker::Immut<'a>, K, V, Type> {}
impl<'a, K: 'a, V: 'a, Type> Clone for NodeRef<marker::Immut<'a>, K, V, Type> {
    fn clone(&self) -> Self {
        *self
    }
}

unsafe impl<BorrowType, K: Sync, V: Sync, Type> Sync for NodeRef<BorrowType, K, V, Type> {}

unsafe impl<'a, K: Sync + 'a, V: Sync + 'a, Type> Send for NodeRef<marker::Immut<'a>, K, V, Type> {}
unsafe impl<'a, K: Send + 'a, V: Send + 'a, Type> Send for NodeRef<marker::Mut<'a>, K, V, Type> {}
unsafe impl<'a, K: Send + 'a, V: Send + 'a, Type> Send for NodeRef<marker::ValMut<'a>, K, V, Type> {}
unsafe impl<K: Send, V: Send, Type> Send for NodeRef<marker::Owned, K, V, Type> {}

impl<BorrowType, K, V> NodeRef<BorrowType, K, V, marker::Internal> {




    fn as_internal_ptr(&self) -> *const InternalNode<K, V> {
        self.node.as_ptr() as *const InternalNode<K, V>
    }
}

impl<'a, K, V> NodeRef<marker::Mut<'a>, K, V, marker::Internal> {


    fn as_internal(&mut self) -> &InternalNode<K, V> {
        unsafe { &*self.as_internal_ptr() }
    }
}

impl<'a, K, V> NodeRef<marker::Mut<'a>, K, V, marker::Internal> {



    fn as_internal_mut(&mut self) -> &mut InternalNode<K, V> {
        unsafe { &mut *(self.node.as_ptr() as *mut InternalNode<K, V>) }
    }
}

impl<BorrowType, K, V, Type> NodeRef<BorrowType, K, V, Type> {





    pub fn len(&self) -> usize {


        unsafe { usize::from((*self.as_leaf_ptr()).len) }
    }



    pub fn height(&self) -> usize {
        self.height
    }


    fn reborrow(&self) -> NodeRef<marker::Immut<'_>, K, V, Type> {
        NodeRef { height: self.height, node: self.node, _marker: PhantomData }
    }








    fn as_leaf_ptr(&self) -> *const LeafNode<K, V> {



        self.node.as_ptr()
    }





    pub unsafe fn key_at(&self, idx: usize) -> &K {
        unsafe { self.reborrow().into_key_at(idx) }
    }





    unsafe fn val_at(&self, idx: usize) -> &V {
        unsafe { self.reborrow().into_val_at(idx) }
    }
}

impl<BorrowType, K, V> NodeRef<BorrowType, K, V, marker::Internal> {





    unsafe fn edge_at(&self, idx: usize) -> &BoxedNode<K, V> {
        debug_assert!(idx <= self.len());
        let node = self.as_internal_ptr();
        unsafe { (*node).edges.get_unchecked(idx).assume_init_ref() }
    }
}

impl<BorrowType, K, V, Type> NodeRef<BorrowType, K, V, Type> {







    pub fn ascend(
        self,
    ) -> Result<Handle<NodeRef<BorrowType, K, V, marker::Internal>, marker::Edge>, Self> {


        let leaf_ptr = self.as_leaf_ptr();
        unsafe { (*leaf_ptr).parent }
            .as_ref()
            .map(|parent| Handle {
                node: NodeRef {
                    height: self.height + 1,
                    node: parent.cast(),
                    _marker: PhantomData,
                },
                idx: unsafe { usize::from((*leaf_ptr).parent_idx.assume_init()) },
                _marker: PhantomData,
            })
            .ok_or(self)
    }

    pub fn first_edge(self) -> Handle<Self, marker::Edge> {
        unsafe { Handle::new_edge(self, 0) }
    }

    pub fn last_edge(self) -> Handle<Self, marker::Edge> {
        let len = self.len();
        unsafe { Handle::new_edge(self, len) }
    }


    pub fn first_kv(self) -> Handle<Self, marker::KV> {
        let len = self.len();
        assert!(len > 0);
        unsafe { Handle::new_kv(self, 0) }
    }


    pub fn last_kv(self) -> Handle<Self, marker::KV> {
        let len = self.len();
        assert!(len > 0);
        unsafe { Handle::new_kv(self, len - 1) }
    }
}

impl<'a, K: 'a, V: 'a, Type> NodeRef<marker::Immut<'a>, K, V, Type> {

    fn into_leaf(self) -> &'a LeafNode<K, V> {


        unsafe { &(*self.as_leaf_ptr()) }
    }
}

impl<K, V> NodeRef<marker::Owned, K, V, marker::LeafOrInternal> {



    pub unsafe fn deallocate_and_ascend(
        self,
    ) -> Option<Handle<NodeRef<marker::Owned, K, V, marker::Internal>, marker::Edge>> {
        let height = self.height;
        let node = self.node;
        let ret = self.ascend().ok();
        unsafe {
            Global.dealloc(
                node.cast(),
                if height > 0 {
                    Layout::new::<InternalNode<K, V>>()
                } else {
                    Layout::new::<LeafNode<K, V>>()
                },
            );
        }
        ret
    }
}

impl<'a, K, V, Type> NodeRef<marker::Mut<'a>, K, V, Type> {


    unsafe fn cast_unchecked<NewType>(self) -> NodeRef<marker::Mut<'a>, K, V, NewType> {
        NodeRef { height: self.height, node: self.node, _marker: PhantomData }
    }











    unsafe fn reborrow_mut(&mut self) -> NodeRef<marker::Mut<'_>, K, V, Type> {
        NodeRef { height: self.height, node: self.node, _marker: PhantomData }
    }







    fn as_leaf_mut(&mut self) -> &'a mut LeafNode<K, V> {
        unsafe { &mut (*self.node.as_ptr()) }
    }





    pub unsafe fn key_mut_at(&mut self, idx: usize) -> &mut K {
        unsafe { self.reborrow_mut().into_key_mut_at(idx) }
    }





    pub unsafe fn val_mut_at(&mut self, idx: usize) -> &mut V {
        unsafe { self.reborrow_mut().into_val_mut_at(idx) }
    }

    fn keys_mut(&mut self) -> &mut [K]
    where
        K: 'a,
        V: 'a,
    {




        unsafe {
            slice::from_raw_parts_mut(
                MaybeUninit::slice_as_mut_ptr(&mut self.as_leaf_mut().keys),
                self.len(),
            )
        }
    }

    fn vals_mut(&mut self) -> &mut [V]
    where
        K: 'a,
        V: 'a,
    {




        unsafe {
            slice::from_raw_parts_mut(
                MaybeUninit::slice_as_mut_ptr(&mut self.as_leaf_mut().vals),
                self.len(),
            )
        }
    }
}

impl<'a, K, V> NodeRef<marker::Mut<'a>, K, V, marker::Internal> {
    fn edges_mut(&mut self) -> &mut [BoxedNode<K, V>] {
        unsafe {
            slice::from_raw_parts_mut(
                MaybeUninit::slice_as_mut_ptr(&mut self.as_internal_mut().edges),
                self.len() + 1,
            )
        }
    }
}

impl<'a, K: 'a, V: 'a, Type> NodeRef<marker::Immut<'a>, K, V, Type> {


    unsafe fn into_key_at(self, idx: usize) -> &'a K {
        unsafe { self.into_leaf().keys.get_unchecked(idx).assume_init_ref() }
    }



    unsafe fn into_val_at(self, idx: usize) -> &'a V {
        unsafe { self.into_leaf().vals.get_unchecked(idx).assume_init_ref() }
    }
}

impl<'a, K: 'a, V: 'a, Type> NodeRef<marker::Mut<'a>, K, V, Type> {


    unsafe fn into_key_mut_at(mut self, idx: usize) -> &'a mut K {
        debug_assert!(idx < self.len());

        let leaf = self.as_leaf_mut();
        unsafe { leaf.keys.get_unchecked_mut(idx).assume_init_mut() }
    }



    unsafe fn into_val_mut_at(mut self, idx: usize) -> &'a mut V {
        debug_assert!(idx < self.len());

        let leaf = self.as_leaf_mut();
        unsafe { leaf.vals.get_unchecked_mut(idx).assume_init_mut() }
    }
}

impl<'a, K, V, Type> NodeRef<marker::ValMut<'a>, K, V, Type> {


    unsafe fn into_key_val_mut_at(self, idx: usize) -> (&'a K, &'a mut V) {



        let leaf = self.node.as_ptr();

        let keys: *const [_] = unsafe { &raw const (*leaf).keys };
        let vals: *mut [_] = unsafe { &raw mut (*leaf).vals };

        let key = unsafe { (&*keys.get_unchecked(idx)).assume_init_ref() };
        let val = unsafe { (&mut *vals.get_unchecked_mut(idx)).assume_init_mut() };
        (key, val)
    }
}

impl<'a, K: 'a, V: 'a> NodeRef<marker::Mut<'a>, K, V, marker::Leaf> {

    pub fn push(&mut self, key: K, val: V) {
        let len = &mut self.as_leaf_mut().len;
        let idx = usize::from(*len);
        assert!(idx < CAPACITY);
        *len += 1;
        unsafe {
            ptr::write(self.key_mut_at(idx), key);
            ptr::write(self.val_mut_at(idx), val);
        }
    }


    fn push_front(&mut self, key: K, val: V) {
        debug_assert!(self.len() < CAPACITY);

        unsafe {
            slice_insert(self.keys_mut(), 0, key);
            slice_insert(self.vals_mut(), 0, val);
        }
        self.as_leaf_mut().len += 1;
    }
}

impl<'a, K, V> NodeRef<marker::Mut<'a>, K, V, marker::Internal> {


    unsafe fn correct_childrens_parent_links<R: Iterator<Item = usize>>(&mut self, range: R) {
        for i in range {
            debug_assert!(i <= self.len());
            unsafe { Handle::new_edge(self.reborrow_mut(), i) }.correct_parent_link();
        }
    }

    fn correct_all_childrens_parent_links(&mut self) {
        let len = self.len();
        unsafe { self.correct_childrens_parent_links(0..=len) };
    }
}

impl<'a, K: 'a, V: 'a> NodeRef<marker::Mut<'a>, K, V, marker::Internal> {


    pub fn push(&mut self, key: K, val: V, edge: Root<K, V>) {
        assert!(edge.height == self.height - 1);

        let len = &mut self.as_leaf_mut().len;
        let idx = usize::from(*len);
        assert!(idx < CAPACITY);
        *len += 1;
        unsafe {
            ptr::write(self.key_mut_at(idx), key);
            ptr::write(self.val_mut_at(idx), val);
            self.as_internal_mut().edges.get_unchecked_mut(idx + 1).write(edge.node);
            Handle::new_edge(self.reborrow_mut(), idx + 1).correct_parent_link();
        }
    }



    pub fn push_front(&mut self, key: K, val: V, edge: Root<K, V>) {
        assert!(edge.height == self.height - 1);
        assert!(self.len() < CAPACITY);

        unsafe {
            slice_insert(self.keys_mut(), 0, key);
            slice_insert(self.vals_mut(), 0, val);
            slice_insert(
                slice::from_raw_parts_mut(
                    MaybeUninit::slice_as_mut_ptr(&mut self.as_internal_mut().edges),
                    self.len() + 1,
                ),
                0,
                edge.node,
            );
        }

        self.as_leaf_mut().len += 1;

        self.correct_all_childrens_parent_links();
    }
}

impl<'a, K: 'a, V: 'a> NodeRef<marker::Mut<'a>, K, V, marker::LeafOrInternal> {



    fn pop(&mut self) -> (K, V, Option<Root<K, V>>) {
        debug_assert!(self.len() > 0);

        let idx = self.len() - 1;

        unsafe {
            let key = ptr::read(self.key_at(idx));
            let val = ptr::read(self.val_at(idx));
            let edge = match self.reborrow_mut().force() {
                ForceResult::Leaf(_) => None,
                ForceResult::Internal(internal) => {
                    let edge = ptr::read(internal.edge_at(idx + 1));
                    let mut new_root = Root { node: edge, height: internal.height - 1 };
                    new_root.node_as_mut().as_leaf_mut().parent = None;
                    Some(new_root)
                }
            };

            self.as_leaf_mut().len -= 1;
            (key, val, edge)
        }
    }




    fn pop_front(&mut self) -> (K, V, Option<Root<K, V>>) {
        debug_assert!(self.len() > 0);

        let old_len = self.len();

        unsafe {
            let key = slice_remove(self.keys_mut(), 0);
            let val = slice_remove(self.vals_mut(), 0);
            let edge = match self.reborrow_mut().force() {
                ForceResult::Leaf(_) => None,
                ForceResult::Internal(mut internal) => {
                    let edge = slice_remove(internal.edges_mut(), 0);
                    let mut new_root = Root { node: edge, height: internal.height - 1 };
                    new_root.node_as_mut().as_leaf_mut().parent = None;

                    internal.correct_childrens_parent_links(0..old_len);

                    Some(new_root)
                }
            };

            self.as_leaf_mut().len -= 1;

            (key, val, edge)
        }
    }

    fn into_kv_pointers_mut(mut self) -> (*mut K, *mut V) {
        (self.keys_mut().as_mut_ptr(), self.vals_mut().as_mut_ptr())
    }
}

impl<BorrowType, K, V> NodeRef<BorrowType, K, V, marker::LeafOrInternal> {

    pub fn force(
        self,
    ) -> ForceResult<
        NodeRef<BorrowType, K, V, marker::Leaf>,
        NodeRef<BorrowType, K, V, marker::Internal>,
    > {
        if self.height == 0 {
            ForceResult::Leaf(NodeRef {
                height: self.height,
                node: self.node,
                _marker: PhantomData,
            })
        } else {
            ForceResult::Internal(NodeRef {
                height: self.height,
                node: self.node,
                _marker: PhantomData,
            })
        }
    }
}









pub struct Handle<Node, Type> {
    node: Node,
    idx: usize,
    _marker: PhantomData<Type>,
}

impl<Node: Copy, Type> Copy for Handle<Node, Type> {}


impl<Node: Copy, Type> Clone for Handle<Node, Type> {
    fn clone(&self) -> Self {
        *self
    }
}

impl<Node, Type> Handle<Node, Type> {

    pub fn into_node(self) -> Node {
        self.node
    }


    pub fn idx(&self) -> usize {
        self.idx
    }
}

impl<BorrowType, K, V, NodeType> Handle<NodeRef<BorrowType, K, V, NodeType>, marker::KV> {


    pub unsafe fn new_kv(node: NodeRef<BorrowType, K, V, NodeType>, idx: usize) -> Self {
        debug_assert!(idx < node.len());

        Handle { node, idx, _marker: PhantomData }
    }

    pub fn left_edge(self) -> Handle<NodeRef<BorrowType, K, V, NodeType>, marker::Edge> {
        unsafe { Handle::new_edge(self.node, self.idx) }
    }

    pub fn right_edge(self) -> Handle<NodeRef<BorrowType, K, V, NodeType>, marker::Edge> {
        unsafe { Handle::new_edge(self.node, self.idx + 1) }
    }
}

impl<BorrowType, K, V, NodeType, HandleType> PartialEq
    for Handle<NodeRef<BorrowType, K, V, NodeType>, HandleType>
{
    fn eq(&self, other: &Self) -> bool {
        self.node.node == other.node.node && self.idx == other.idx
    }
}

impl<BorrowType, K, V, NodeType, HandleType> PartialOrd
    for Handle<NodeRef<BorrowType, K, V, NodeType>, HandleType>
{
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        if self.node.node == other.node.node { Some(self.idx.cmp(&other.idx)) } else { None }
    }
}

impl<BorrowType, K, V, NodeType, HandleType>
    Handle<NodeRef<BorrowType, K, V, NodeType>, HandleType>
{

    pub fn reborrow(&self) -> Handle<NodeRef<marker::Immut<'_>, K, V, NodeType>, HandleType> {

        Handle { node: self.node.reborrow(), idx: self.idx, _marker: PhantomData }
    }
}

impl<'a, K, V, NodeType, HandleType> Handle<NodeRef<marker::Mut<'a>, K, V, NodeType>, HandleType> {





    pub unsafe fn reborrow_mut(
        &mut self,
    ) -> Handle<NodeRef<marker::Mut<'_>, K, V, NodeType>, HandleType> {

        Handle { node: unsafe { self.node.reborrow_mut() }, idx: self.idx, _marker: PhantomData }
    }
}

impl<BorrowType, K, V, NodeType> Handle<NodeRef<BorrowType, K, V, NodeType>, marker::Edge> {


    pub unsafe fn new_edge(node: NodeRef<BorrowType, K, V, NodeType>, idx: usize) -> Self {
        debug_assert!(idx <= node.len());

        Handle { node, idx, _marker: PhantomData }
    }

    pub fn left_kv(self) -> Result<Handle<NodeRef<BorrowType, K, V, NodeType>, marker::KV>, Self> {
        if self.idx > 0 {
            Ok(unsafe { Handle::new_kv(self.node, self.idx - 1) })
        } else {
            Err(self)
        }
    }

    pub fn right_kv(self) -> Result<Handle<NodeRef<BorrowType, K, V, NodeType>, marker::KV>, Self> {
        if self.idx < self.node.len() {
            Ok(unsafe { Handle::new_kv(self.node, self.idx) })
        } else {
            Err(self)
        }
    }
}

enum InsertionPlace {
    Left(usize),
    Right(usize),
}






fn splitpoint(edge_idx: usize) -> (usize, InsertionPlace) {
    debug_assert!(edge_idx <= CAPACITY);

    match edge_idx {
        0..EDGE_IDX_LEFT_OF_CENTER => (KV_IDX_CENTER - 1, InsertionPlace::Left(edge_idx)),
        EDGE_IDX_LEFT_OF_CENTER => (KV_IDX_CENTER, InsertionPlace::Left(edge_idx)),
        EDGE_IDX_RIGHT_OF_CENTER => (KV_IDX_CENTER, InsertionPlace::Right(0)),
        _ => (KV_IDX_CENTER + 1, InsertionPlace::Right(edge_idx - (KV_IDX_CENTER + 1 + 1))),
    }
}

impl<'a, K: 'a, V: 'a, NodeType> Handle<NodeRef<marker::Mut<'a>, K, V, NodeType>, marker::Edge> {





    fn leafy_insert_fit(&mut self, key: K, val: V) {
        debug_assert!(self.node.len() < CAPACITY);

        unsafe {
            slice_insert(self.node.keys_mut(), self.idx, key);
            slice_insert(self.node.vals_mut(), self.idx, val);

            self.node.as_leaf_mut().len += 1;
        }
    }
}

impl<'a, K: 'a, V: 'a> Handle<NodeRef<marker::Mut<'a>, K, V, marker::Leaf>, marker::Edge> {





    fn insert_fit(&mut self, key: K, val: V) -> *mut V {
        self.leafy_insert_fit(key, val);
        unsafe { self.node.val_mut_at(self.idx) }
    }
}

impl<'a, K: 'a, V: 'a> Handle<NodeRef<marker::Mut<'a>, K, V, marker::Leaf>, marker::Edge> {




    fn insert(mut self, key: K, val: V) -> (InsertResult<'a, K, V, marker::Leaf>, *mut V) {
        if self.node.len() < CAPACITY {
            let val_ptr = self.insert_fit(key, val);
            let kv = unsafe { Handle::new_kv(self.node, self.idx) };
            (InsertResult::Fit(kv), val_ptr)
        } else {
            let (middle_kv_idx, insertion) = splitpoint(self.idx);
            let middle = unsafe { Handle::new_kv(self.node, middle_kv_idx) };
            let (mut left, k, v, mut right) = middle.split();
            let mut insertion_edge = match insertion {
                InsertionPlace::Left(insert_idx) => unsafe {
                    Handle::new_edge(left.reborrow_mut(), insert_idx)
                },
                InsertionPlace::Right(insert_idx) => unsafe {
                    Handle::new_edge(
                        right.node_as_mut().cast_unchecked::<marker::Leaf>(),
                        insert_idx,
                    )
                },
            };
            let val_ptr = insertion_edge.insert_fit(key, val);
            (InsertResult::Split(SplitResult { left: left.forget_type(), k, v, right }), val_ptr)
        }
    }
}

impl<'a, K, V> Handle<NodeRef<marker::Mut<'a>, K, V, marker::Internal>, marker::Edge> {


    fn correct_parent_link(mut self) {
        let idx = self.idx as u16;
        let ptr = NonNull::new(self.node.as_internal_mut());
        let mut child = self.descend();
        child.as_leaf_mut().parent = ptr;
        child.as_leaf_mut().parent_idx.write(idx);
    }
}

impl<'a, K: 'a, V: 'a> Handle<NodeRef<marker::Mut<'a>, K, V, marker::Internal>, marker::Edge> {



    fn insert_fit(&mut self, key: K, val: V, edge: Root<K, V>) {
        debug_assert!(edge.height == self.node.height - 1);

        unsafe {
            slice_insert(self.node.edges_mut(), self.idx + 1, edge.node);
            self.leafy_insert_fit(key, val);

            self.node.correct_childrens_parent_links((self.idx + 1)..=self.node.len());
        }
    }




    fn insert(
        mut self,
        key: K,
        val: V,
        edge: Root<K, V>,
    ) -> InsertResult<'a, K, V, marker::Internal> {
        assert!(edge.height == self.node.height - 1);

        if self.node.len() < CAPACITY {
            self.insert_fit(key, val, edge);
            let kv = unsafe { Handle::new_kv(self.node, self.idx) };
            InsertResult::Fit(kv)
        } else {
            let (middle_kv_idx, insertion) = splitpoint(self.idx);
            let middle = unsafe { Handle::new_kv(self.node, middle_kv_idx) };
            let (mut left, k, v, mut right) = middle.split();
            match insertion {
                InsertionPlace::Left(insert_idx) => unsafe {
                    Handle::new_edge(left.reborrow_mut(), insert_idx).insert_fit(key, val, edge);
                },
                InsertionPlace::Right(insert_idx) => unsafe {
                    Handle::new_edge(
                        right.node_as_mut().cast_unchecked::<marker::Internal>(),
                        insert_idx,
                    )
                    .insert_fit(key, val, edge);
                },
            }
            InsertResult::Split(SplitResult { left: left.forget_type(), k, v, right })
        }
    }
}

impl<'a, K: 'a, V: 'a> Handle<NodeRef<marker::Mut<'a>, K, V, marker::Leaf>, marker::Edge> {







    pub fn insert_recursing(
        self,
        key: K,
        value: V,
    ) -> (InsertResult<'a, K, V, marker::LeafOrInternal>, *mut V) {
        let (mut split, val_ptr) = match self.insert(key, value) {
            (InsertResult::Fit(handle), ptr) => {
                return (InsertResult::Fit(handle.forget_node_type()), ptr);
            }
            (InsertResult::Split(split), val_ptr) => (split, val_ptr),
        };

        loop {
            split = match split.left.ascend() {
                Ok(parent) => match parent.insert(split.k, split.v, split.right) {
                    InsertResult::Fit(handle) => {
                        return (InsertResult::Fit(handle.forget_node_type()), val_ptr);
                    }
                    InsertResult::Split(split) => split,
                },
                Err(root) => {
                    return (InsertResult::Split(SplitResult { left: root, ..split }), val_ptr);
                }
            };
        }
    }
}

impl<BorrowType, K, V> Handle<NodeRef<BorrowType, K, V, marker::Internal>, marker::Edge> {




    pub fn descend(self) -> NodeRef<BorrowType, K, V, marker::LeafOrInternal> {







        let internal_node = self.node.as_internal_ptr();
        NodeRef {
            height: self.node.height - 1,
            node: unsafe { (&*(*internal_node).edges.get_unchecked(self.idx).as_ptr()).as_ptr() },
            _marker: PhantomData,
        }
    }
}

impl<'a, K: 'a, V: 'a, NodeType> Handle<NodeRef<marker::Immut<'a>, K, V, NodeType>, marker::KV> {
    pub fn into_kv(self) -> (&'a K, &'a V) {
        (unsafe { self.node.into_key_at(self.idx) }, unsafe { self.node.into_val_at(self.idx) })
    }
}

impl<'a, K: 'a, V: 'a, NodeType> Handle<NodeRef<marker::Mut<'a>, K, V, NodeType>, marker::KV> {
    pub fn into_key_mut(self) -> &'a mut K {
        unsafe { self.node.into_key_mut_at(self.idx) }
    }

    pub fn into_val_mut(self) -> &'a mut V {
        unsafe { self.node.into_val_mut_at(self.idx) }
    }
}

impl<'a, K, V, NodeType> Handle<NodeRef<marker::ValMut<'a>, K, V, NodeType>, marker::KV> {
    pub fn into_kv_valmut(self) -> (&'a K, &'a mut V) {
        unsafe { self.node.into_key_val_mut_at(self.idx) }
    }
}

impl<'a, K: 'a, V: 'a, NodeType> Handle<NodeRef<marker::Mut<'a>, K, V, NodeType>, marker::KV> {
    pub fn kv_mut(&mut self) -> (&mut K, &mut V) {


        let leaf = self.node.as_leaf_mut();
        let key = unsafe { leaf.keys.get_unchecked_mut(self.idx).assume_init_mut() };
        let val = unsafe { leaf.vals.get_unchecked_mut(self.idx).assume_init_mut() };
        (key, val)
    }
}

impl<'a, K: 'a, V: 'a, NodeType> Handle<NodeRef<marker::Mut<'a>, K, V, NodeType>, marker::KV> {


    fn leafy_split(&mut self, new_node: &mut LeafNode<K, V>) -> (K, V, usize) {
        unsafe {
            let k = ptr::read(self.node.key_at(self.idx));
            let v = ptr::read(self.node.val_at(self.idx));

            let new_len = self.node.len() - self.idx - 1;

            ptr::copy_nonoverlapping(
                self.node.key_at(self.idx + 1),
                MaybeUninit::slice_as_mut_ptr(&mut new_node.keys),
                new_len,
            );
            ptr::copy_nonoverlapping(
                self.node.val_at(self.idx + 1),
                MaybeUninit::slice_as_mut_ptr(&mut new_node.vals),
                new_len,
            );

            self.node.as_leaf_mut().len = self.idx as u16;
            new_node.len = new_len as u16;
            (k, v, new_len)
        }
    }
}

impl<'a, K: 'a, V: 'a> Handle<NodeRef<marker::Mut<'a>, K, V, marker::Leaf>, marker::KV> {







    pub fn split(mut self) -> (NodeRef<marker::Mut<'a>, K, V, marker::Leaf>, K, V, Root<K, V>) {
        unsafe {
            let mut new_node = Box::new(LeafNode::new());

            let (k, v, _) = self.leafy_split(&mut new_node);

            (self.node, k, v, Root { node: BoxedNode::from_leaf(new_node), height: 0 })
        }
    }



    pub fn remove(
        mut self,
    ) -> ((K, V), Handle<NodeRef<marker::Mut<'a>, K, V, marker::Leaf>, marker::Edge>) {
        unsafe {
            let k = slice_remove(self.node.keys_mut(), self.idx);
            let v = slice_remove(self.node.vals_mut(), self.idx);
            self.node.as_leaf_mut().len -= 1;
            ((k, v), self.left_edge())
        }
    }
}

impl<'a, K, V> Handle<NodeRef<marker::Mut<'a>, K, V, marker::Internal>, marker::KV> {



    pub fn can_merge(&self) -> bool {
        (self.reborrow().left_edge().descend().len()
            + self.reborrow().right_edge().descend().len()
            + 1)
            <= CAPACITY
    }
}

impl<'a, K: 'a, V: 'a> Handle<NodeRef<marker::Mut<'a>, K, V, marker::Internal>, marker::KV> {







    pub fn split(mut self) -> (NodeRef<marker::Mut<'a>, K, V, marker::Internal>, K, V, Root<K, V>) {
        unsafe {
            let mut new_node = Box::new(InternalNode::new());

            let (k, v, new_len) = self.leafy_split(&mut new_node.data);
            let height = self.node.height;
            let old_node = &*self.node.as_internal_ptr();

            ptr::copy_nonoverlapping(
                old_node.edges.as_ptr().add(self.idx + 1),
                new_node.edges.as_mut_ptr(),
                new_len + 1,
            );

            let mut new_root = Root { node: BoxedNode::from_internal(new_node), height };

            new_root.node_as_mut().cast_unchecked().correct_childrens_parent_links(0..=new_len);

            (self.node, k, v, new_root)
        }
    }






    pub fn merge(
        mut self,
    ) -> Handle<NodeRef<marker::Mut<'a>, K, V, marker::Internal>, marker::Edge> {
        let self1 = unsafe { ptr::read(&self) };
        let self2 = unsafe { ptr::read(&self) };
        let mut left_node = self1.left_edge().descend();
        let left_len = left_node.len();
        let right_node = self2.right_edge().descend();
        let right_len = right_node.len();

        assert!(left_len + right_len < CAPACITY);

        unsafe {
            ptr::write(
                left_node.keys_mut().get_unchecked_mut(left_len),
                slice_remove(self.node.keys_mut(), self.idx),
            );
            ptr::copy_nonoverlapping(
                right_node.key_at(0),
                left_node.keys_mut().as_mut_ptr().add(left_len + 1),
                right_len,
            );
            ptr::write(
                left_node.vals_mut().get_unchecked_mut(left_len),
                slice_remove(self.node.vals_mut(), self.idx),
            );
            ptr::copy_nonoverlapping(
                right_node.val_at(0),
                left_node.vals_mut().as_mut_ptr().add(left_len + 1),
                right_len,
            );

            slice_remove(&mut self.node.edges_mut(), self.idx + 1);
            let self_len = self.node.len();
            self.node.correct_childrens_parent_links(self.idx + 1..self_len);
            self.node.as_leaf_mut().len -= 1;

            left_node.as_leaf_mut().len += right_len as u16 + 1;

            if self.node.height > 1 {


                let mut left_node = left_node.cast_unchecked::<marker::Internal>();
                let right_node = right_node.cast_unchecked::<marker::Internal>();
                ptr::copy_nonoverlapping(
                    right_node.edge_at(0),
                    left_node.edges_mut().as_mut_ptr().add(left_len + 1),
                    right_len + 1,
                );

                left_node.correct_childrens_parent_links(left_len + 1..=left_len + 1 + right_len);

                Global.dealloc(right_node.node.cast(), Layout::new::<InternalNode<K, V>>());
            } else {
                Global.dealloc(right_node.node.cast(), Layout::new::<LeafNode<K, V>>());
            }

            Handle::new_edge(self.node, self.idx)
        }
    }




    pub fn steal_left(&mut self) {
        unsafe {
            let (k, v, edge) = self.reborrow_mut().left_edge().descend().pop();

            let k = mem::replace(self.kv_mut().0, k);
            let v = mem::replace(self.kv_mut().1, v);

            match self.reborrow_mut().right_edge().descend().force() {
                ForceResult::Leaf(mut leaf) => leaf.push_front(k, v),
                ForceResult::Internal(mut internal) => internal.push_front(k, v, edge.unwrap()),
            }
        }
    }




    pub fn steal_right(&mut self) {
        unsafe {
            let (k, v, edge) = self.reborrow_mut().right_edge().descend().pop_front();

            let k = mem::replace(self.kv_mut().0, k);
            let v = mem::replace(self.kv_mut().1, v);

            match self.reborrow_mut().left_edge().descend().force() {
                ForceResult::Leaf(mut leaf) => leaf.push(k, v),
                ForceResult::Internal(mut internal) => internal.push(k, v, edge.unwrap()),
            }
        }
    }


    pub fn bulk_steal_left(&mut self, count: usize) {
        unsafe {
            let mut left_node = ptr::read(self).left_edge().descend();
            let left_len = left_node.len();
            let mut right_node = ptr::read(self).right_edge().descend();
            let right_len = right_node.len();


            assert!(right_len + count <= CAPACITY);
            assert!(left_len >= count);

            let new_left_len = left_len - count;


            {
                let left_kv = left_node.reborrow_mut().into_kv_pointers_mut();
                let right_kv = right_node.reborrow_mut().into_kv_pointers_mut();
                let parent_kv = {
                    let kv = self.kv_mut();
                    (kv.0 as *mut K, kv.1 as *mut V)
                };


                ptr::copy(right_kv.0, right_kv.0.add(count), right_len);
                ptr::copy(right_kv.1, right_kv.1.add(count), right_len);


                move_kv(left_kv, new_left_len + 1, right_kv, 0, count - 1);


                move_kv(parent_kv, 0, right_kv, count - 1, 1);


                move_kv(left_kv, new_left_len, parent_kv, 0, 1);
            }

            left_node.as_leaf_mut().len -= count as u16;
            right_node.as_leaf_mut().len += count as u16;

            match (left_node.force(), right_node.force()) {
                (ForceResult::Internal(left), ForceResult::Internal(mut right)) => {

                    let right_edges = right.reborrow_mut().as_internal_mut().edges.as_mut_ptr();
                    ptr::copy(right_edges, right_edges.add(count), right_len + 1);
                    right.correct_childrens_parent_links(count..count + right_len + 1);

                    move_edges(left, new_left_len + 1, right, 0, count);
                }
                (ForceResult::Leaf(_), ForceResult::Leaf(_)) => {}
                _ => unreachable!(),
            }
        }
    }


    pub fn bulk_steal_right(&mut self, count: usize) {
        unsafe {
            let mut left_node = ptr::read(self).left_edge().descend();
            let left_len = left_node.len();
            let mut right_node = ptr::read(self).right_edge().descend();
            let right_len = right_node.len();


            assert!(left_len + count <= CAPACITY);
            assert!(right_len >= count);

            let new_right_len = right_len - count;


            {
                let left_kv = left_node.reborrow_mut().into_kv_pointers_mut();
                let right_kv = right_node.reborrow_mut().into_kv_pointers_mut();
                let parent_kv = {
                    let kv = self.kv_mut();
                    (kv.0 as *mut K, kv.1 as *mut V)
                };


                move_kv(parent_kv, 0, left_kv, left_len, 1);


                move_kv(right_kv, 0, left_kv, left_len + 1, count - 1);


                move_kv(right_kv, count - 1, parent_kv, 0, 1);


                ptr::copy(right_kv.0.add(count), right_kv.0, new_right_len);
                ptr::copy(right_kv.1.add(count), right_kv.1, new_right_len);
            }

            left_node.as_leaf_mut().len += count as u16;
            right_node.as_leaf_mut().len -= count as u16;

            match (left_node.force(), right_node.force()) {
                (ForceResult::Internal(left), ForceResult::Internal(mut right)) => {
                    move_edges(right.reborrow_mut(), 0, left, left_len + 1, count);


                    let right_edges = right.reborrow_mut().as_internal_mut().edges.as_mut_ptr();
                    ptr::copy(right_edges.add(count), right_edges, new_right_len + 1);
                    right.correct_childrens_parent_links(0..=new_right_len);
                }
                (ForceResult::Leaf(_), ForceResult::Leaf(_)) => {}
                _ => unreachable!(),
            }
        }
    }
}

unsafe fn move_kv<K, V>(
    source: (*mut K, *mut V),
    source_offset: usize,
    dest: (*mut K, *mut V),
    dest_offset: usize,
    count: usize,
) {
    unsafe {
        ptr::copy_nonoverlapping(source.0.add(source_offset), dest.0.add(dest_offset), count);
        ptr::copy_nonoverlapping(source.1.add(source_offset), dest.1.add(dest_offset), count);
    }
}


unsafe fn move_edges<K, V>(
    mut source: NodeRef<marker::Mut<'_>, K, V, marker::Internal>,
    source_offset: usize,
    mut dest: NodeRef<marker::Mut<'_>, K, V, marker::Internal>,
    dest_offset: usize,
    count: usize,
) {
    let source_ptr = source.as_internal().edges.as_ptr();
    let dest_ptr = dest.as_internal_mut().edges.as_mut_ptr();
    unsafe {
        ptr::copy_nonoverlapping(source_ptr.add(source_offset), dest_ptr.add(dest_offset), count);
        dest.correct_childrens_parent_links(dest_offset..dest_offset + count);
    }
}

impl<BorrowType, K, V> NodeRef<BorrowType, K, V, marker::Leaf> {

    pub fn forget_type(self) -> NodeRef<BorrowType, K, V, marker::LeafOrInternal> {
        NodeRef { height: self.height, node: self.node, _marker: PhantomData }
    }
}

impl<BorrowType, K, V> NodeRef<BorrowType, K, V, marker::Internal> {

    pub fn forget_type(self) -> NodeRef<BorrowType, K, V, marker::LeafOrInternal> {
        NodeRef { height: self.height, node: self.node, _marker: PhantomData }
    }
}

impl<BorrowType, K, V> Handle<NodeRef<BorrowType, K, V, marker::Leaf>, marker::Edge> {
    pub fn forget_node_type(
        self,
    ) -> Handle<NodeRef<BorrowType, K, V, marker::LeafOrInternal>, marker::Edge> {
        unsafe { Handle::new_edge(self.node.forget_type(), self.idx) }
    }
}

impl<BorrowType, K, V> Handle<NodeRef<BorrowType, K, V, marker::Internal>, marker::Edge> {
    pub fn forget_node_type(
        self,
    ) -> Handle<NodeRef<BorrowType, K, V, marker::LeafOrInternal>, marker::Edge> {
        unsafe { Handle::new_edge(self.node.forget_type(), self.idx) }
    }
}

impl<BorrowType, K, V> Handle<NodeRef<BorrowType, K, V, marker::Leaf>, marker::KV> {
    pub fn forget_node_type(
        self,
    ) -> Handle<NodeRef<BorrowType, K, V, marker::LeafOrInternal>, marker::KV> {
        unsafe { Handle::new_kv(self.node.forget_type(), self.idx) }
    }
}

impl<BorrowType, K, V> Handle<NodeRef<BorrowType, K, V, marker::Internal>, marker::KV> {
    pub fn forget_node_type(
        self,
    ) -> Handle<NodeRef<BorrowType, K, V, marker::LeafOrInternal>, marker::KV> {
        unsafe { Handle::new_kv(self.node.forget_type(), self.idx) }
    }
}

impl<BorrowType, K, V, HandleType>
    Handle<NodeRef<BorrowType, K, V, marker::LeafOrInternal>, HandleType>
{

    pub fn force(
        self,
    ) -> ForceResult<
        Handle<NodeRef<BorrowType, K, V, marker::Leaf>, HandleType>,
        Handle<NodeRef<BorrowType, K, V, marker::Internal>, HandleType>,
    > {
        match self.node.force() {
            ForceResult::Leaf(node) => {
                ForceResult::Leaf(Handle { node, idx: self.idx, _marker: PhantomData })
            }
            ForceResult::Internal(node) => {
                ForceResult::Internal(Handle { node, idx: self.idx, _marker: PhantomData })
            }
        }
    }
}

impl<'a, K, V> Handle<NodeRef<marker::Mut<'a>, K, V, marker::LeafOrInternal>, marker::Edge> {


    pub fn move_suffix(
        &mut self,
        right: &mut NodeRef<marker::Mut<'a>, K, V, marker::LeafOrInternal>,
    ) {
        unsafe {
            let left_new_len = self.idx;
            let mut left_node = self.reborrow_mut().into_node();

            let right_new_len = left_node.len() - left_new_len;
            let mut right_node = right.reborrow_mut();

            assert!(right_node.len() == 0);
            assert!(left_node.height == right_node.height);

            if right_new_len > 0 {
                let left_kv = left_node.reborrow_mut().into_kv_pointers_mut();
                let right_kv = right_node.reborrow_mut().into_kv_pointers_mut();

                move_kv(left_kv, left_new_len, right_kv, 0, right_new_len);

                left_node.as_leaf_mut().len = left_new_len as u16;
                right_node.as_leaf_mut().len = right_new_len as u16;

                match (left_node.force(), right_node.force()) {
                    (ForceResult::Internal(left), ForceResult::Internal(right)) => {
                        move_edges(left, left_new_len + 1, right, 1, right_new_len);
                    }
                    (ForceResult::Leaf(_), ForceResult::Leaf(_)) => {}
                    _ => unreachable!(),
                }
            }
        }
    }
}

pub enum ForceResult<Leaf, Internal> {
    Leaf(Leaf),
    Internal(Internal),
}



pub struct SplitResult<'a, K, V> {

    pub left: NodeRef<marker::Mut<'a>, K, V, marker::LeafOrInternal>,

    pub k: K,
    pub v: V,

    pub right: Root<K, V>,
}

pub enum InsertResult<'a, K, V, Type> {
    Fit(Handle<NodeRef<marker::Mut<'a>, K, V, Type>, marker::KV>),
    Split(SplitResult<'a, K, V>),
}

pub mod marker {
    use core::marker::PhantomData;

    pub enum Leaf {}
    pub enum Internal {}
    pub enum LeafOrInternal {}

    pub enum Owned {}
    pub struct Immut<'a>(PhantomData<&'a ()>);
    pub struct Mut<'a>(PhantomData<&'a mut ()>);
    pub struct ValMut<'a>(PhantomData<&'a mut ()>);

    pub enum KV {}
    pub enum Edge {}
}

unsafe fn slice_insert<T>(slice: &mut [T], idx: usize, val: T) {
    unsafe {
        ptr::copy(slice.as_ptr().add(idx), slice.as_mut_ptr().add(idx + 1), slice.len() - idx);
        ptr::write(slice.get_unchecked_mut(idx), val);
    }
}

unsafe fn slice_remove<T>(slice: &mut [T], idx: usize) -> T {
    unsafe {
        let ret = ptr::read(slice.get_unchecked(idx));
        ptr::copy(slice.as_ptr().add(idx + 1), slice.as_mut_ptr().add(idx), slice.len() - idx - 1);
        ret
    }
}

#[cfg(test)]
mod tests;
