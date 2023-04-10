# Concurrent State-based Reducer

Currently, there are 3 concurrent state-based reducers implemented:
1. Delta debugging reducer: `ConcurrentStateBasedDeltaReducer.kt` 
2. Token slicer: `ConcurrentStateBasedTokenSlicer.kt`
3. Line slicer: `ConcurrentStateBasedLineSlicer.kt`

### Main Concept
To achieve efficient concurrency on program reduction,
an abstract of `state` is employed.
This `state` contains enough information for a single thread to perform
the **transformation** and a **query**.

##### Workflow in a thread
1. Receive a `state` containing transformation and query information
2. Perform the transformation and issues a property test (aka, query)
3. Return the result (interesting and transform edits)

##### Workflow in main
1. Parsing the input (e.g., DD parses the input to a list of configurations or Line Slicer parses the input to a list of lines)
2. Create initial `state`
3. Assign each `state` to a thread when possible (until run out of `state`)
4. Check result:
   1. If an uninteresting result, ignore.
   2. If an interesting result, kill the rest of running thread. Apply the successful transformation edits to the current best program

More details see `AbstractStateBasedConcurrentReducer.kt`.

### Parallel Startpoint
The approach depicted above is also implemented in C-Vise,
while C-Reduce adopted a lower-level parallelization,
where only the query portion is paralleled.
The main performs all transformation and concurrently issues queries.  
In theory, when the transformation gets more complicated and takes longer to perform,
parallelizing both transformation and query leads to better efficiency.


### Related
- GitHub issue: [study c-vise #246](https://github.com/chengniansun/perses-private/issues/246)
- [C-Vise](https://github.com/marxin/cvise): a super-parallel Python port of the C-Reduce.
- John Regehr's [blog](https://blog.regehr.org/archives/749)
