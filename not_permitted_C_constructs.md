# Not permitted C constructs

---

## sys_call
No sys_call permitted, wrap between macro conditional block using definition of `__SYNTHESIS__` as condition.

```
#ifndef __SYNTHESIS__
    /*
     * ... performs sys_call
     */
#endif
```

---

## Dynamic memory usage
### `malloc` and `new`
**Must** be removed befor synthesis since it's uded to define design's functionality, use a macro contitional block with the user-defined `NO_SYNTH` variable to switch between code implementations.

```
#ifdef NO_SYNTH
    /*
     * ... int* mem_ptr = (int*)malloc(sizeof(int));
     */
#else
    /*
     * ... int mem;
     * ... int *mem_ptr = &mem;
     */
#endif
```

---

## Pointer limitations

### Casting:
>Vivado HLS only supports pointer casting between native C types.

### Pointer Arrays
>Vivado HLS supports pointer arrays for synthesis, provided that each pointer points to a scalar or
an array of scalars. Arrays of pointers cannot point to additional pointers.

### Function pointers
>Not supported