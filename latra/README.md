# Latra

Latra is a template-based, language-agnostic code
transformation framework for program reduction.
It supports user-defined, language-specific
transformations through an expressive domain-specific
language (DSL).

---

## DSL Syntax Overview
Latra’s DSL allows users to define transformations 
using matching and rewriting templates. Users define 
a transformation by calling `registerTransformation` 
with the following fields:

```Kotlin
val ruleName = registerTransformation(
  name = "RuleName",
  from = "int :[name]() { :[body+] }",
  such_as = "int func1() { return 1; }",
  to = "int :[name]() { }",
  where = ":[name] != main",
  global_replace = {
    replace(
      pattern = "int :[var] = :[val];",
      such_as = "int x = 2;",
      inside = "body",
      with = "int :[var] = 0;", 
      mustMatch = true,
      matchAll = false,
    )
  }
)
```

### Parameters
- **name**: Name of the transformation

#### Matching Template
- **from**: Match pattern using labeled holes
(`:[label]`, `:[label+]`) that allows flexibility, 
where `:[label+]` indicates matching one or more tokens
- **such_as**: Example input that matches the pattern
(optional but improves accuracy)

#### Rewriting Template
- **to**: Rewrite pattern (can be empty to delete)
- **global_replace**: One or more `replace(...)` 
calls for substitution
- **Note**: Previously defined holes are reused
in `to` and `with` in `replace(...)` for rewriting logic

---

## `such_as` clauses

This is to match the most general rules.
```
{g:  .....   :}
```



This is to match the most specific rules.
```
{:  .....   :}
```

## `global_replace` Options

Each `replace(...)` call supports additional control flags:

```kotlin
replace(
    pattern = "int :[var] = :[val];",
    such_as = "int x = 2;",
    inside = "body",
    with = "int :[var] = 0;",
    mustMatch = true,
    matchAll = false,
)
```

### Option Descriptions

- `pattern`: What to search for (can include either new 
or defined holes)
- `with`: What to replace the match with (only allow 
holes previously defined)
- `inside`: (Optional) Restricts the scope of the
replacement to within a specific matched label
- `mustMatch`:
    - `true`: Replacement **must** occur at least once,
  or the entire transformation rule is skipped
    - `false`: Replacement is optional
- `matchAll`:
    - `true`: Replace **all** matches
    - `false`: Replace only the **first** match

---

## Example: Copy Propagation

```kotlin
val copyPropagation = registerTransformation(
  name = "CopyPropagation",
  from = ":[type+] :[a] = :[b+];",
  such_as = "int a = b;",
  to = ":[type] :[a] = :[b];",
  global_replace = {
    replace(
      pattern = ":[type+] :[c] = :[a];",
      with = "",
    )
    replace(
      pattern = ":[c]",
      with = ":[a]",
    )
  },
)
```

### What it does:
- Matches assignments like `int a = b;`
- Rewrites them to remove extra type annotations or copies
- Propagates the original variable `b` to replace downstream copies of `a`
