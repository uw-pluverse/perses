



class EnumCantBeInstantiated {
    enum E { A, B, C }

    E e = new E("a");
}
