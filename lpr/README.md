# LPR: LLM-based Program Reduction

LPR adds reduction passes that ask a Large Language Model (LLM) to perform
*semantic* transformations the token- and tree-based reducers cannot easily do
on their own (e.g., inlining a function or unrolling a loop). Simplifying the
program at a higher level can unblock the other reducers and shrink the result
further.

LPR is **off by default**; enable it with `--enable-lpr true`.

## Layout

```
lpr/
├── README.md                          # this file
├── scripts/                           # LLM client scripts (Python)
│   ├── llm_client.py                  # default / reference client
│   ├── llm_client_mock_to_test_*.py   # deterministic mocks used by the tests
│   └── BUILD
├── src/org/perses/reduction/reducer/lpr/   # the reducers
└── test/org/perses/reduction/reducer/lpr/  # unit, functional, and golden tests
```

The reducer passes (subclasses of `AbstractLlmBasedReducer`):

| Reducer                                 | Transformation                                   |
|-----------------------------------------|--------------------------------------------------|
| `LlmBasedFunctionInliningReducer`       | Inline a function into its call sites            |
| `LlmBasedLoopUnrollingReducer`          | Unroll a loop                                    |
| `LlmBasedDataTypeEliminationReducer`    | Remove a redundant data type (e.g., a `typedef`) |
| `LlmBasedDataTypeSimplificationReducer` | Replace a complex data type with a simpler one   |
| `LlmBasedVariableEliminationReducer`    | Remove an intermediate / unused variable         |

## How LPR talks to an LLM

LPR does not call any LLM API directly. Instead it shells out to an **LLM client
script** that you can supply. For every request, Perses invokes the script as:

```
<client-script> --input-file <request.json> --output-file <response.json>
```

- `request.json` is a JSON object whose `message` field holds the full prompt.
- The script must write `response.json` as a **JSON array of strings**, where
  each string is one independent completion. LPR inspects each completion for a
  Markdown bullet list (the "target list") or a fenced code block (the
  transformed program).

That is the entire contract — the script is free to use any provider, model,
language, or local runtime, because Perses only passes it the two file paths.

### Providing your own script

Point `--llm-client-script` at any executable that honors the contract above:

```bash
java -jar perses_deploy.jar \
    --test-script r.sh --input-file t.c \
    --enable-lpr true \
    --llm-client-script /path/to/my_llm_client.py
```

Perses forwards **only** `--input-file` and `--output-file`; it does not pass the
model name, endpoint, API key, temperature, or completion count. Those live in
your script. The easiest path is to copy the reference client and adjust it:

```bash
cp lpr/scripts/llm_client.py my_llm_client.py
chmod +x my_llm_client.py
# edit the argparse defaults (--model / --base-url / --api-key / ...),
# or have them read environment variables, e.g.
#   default=os.getenv("LPR_MODEL", "codellama:13b")
```

Keep secrets such as API keys in environment variables rather than on the command
line.

### Default behavior when `--llm-client-script` is not specified

If you omit `--llm-client-script`, LPR **falls back to a bundled default client**
— a copy of [`scripts/llm_client.py`](scripts/llm_client.py) that is materialized
to a temporary file and executed. This default is an OpenAI-compatible client
that, by default, targets a **local [ollama](https://ollama.com) server** at
`http://localhost:11434/v1` using model `codellama:13b` and requests 5
completions per call.

The fallback is **not silent**: when it is used, Perses emits a notice in the
reduction output stating that the bundled default is being used, where it was
materialized, what it targets, and how to override it.

So the simplest end-to-end setup is to run ollama locally and let the default
client talk to it:

```bash
# 1. Install ollama (https://ollama.com) and start it.
ollama serve

# 2. Pull the model the default client expects.
ollama pull codellama:13b

# 3. Run Perses with LPR enabled (no --llm-client-script needed).
java -jar perses_deploy.jar \
    --test-script r.sh --input-file t.c \
    --enable-lpr true
```

## Flags

| Flag                          | Default  | Meaning                                                       |
|-------------------------------|----------|---------------------------------------------------------------|
| `--enable-lpr <bool>`         | `false`  | Turn the LPR passes on.                                        |
| `--lpr-fixpoint <bool>`       | `false`  | After a transformation makes progress, re-run the LPR passes. |
| `--llm-client-script <path>`  | *(none)* | Use your own LLM client instead of the bundled default.       |

(Defined in `src/org/perses/cmd/LPRFlagGroup.kt`, which stays in the core CLI
module alongside the other flag groups.)

## How it works

For each enabled pass, `AbstractLlmBasedReducer.internalReduce`:

1. **Primary question** — asks the LLM to list the *targets* to transform (e.g.,
   the functions to inline), returned as a Markdown bullet list.
2. **Follow-up question** — for each target, asks the LLM for the *whole*
   transformed program, returned in a fenced code block. The LLM may return
   several candidate completions.
3. **Property test** — each parsable candidate becomes a tree edit and is tested
   against your `--test-script`. The best interesting candidate is applied
   immediately, so later targets build on top of it.
4. With `--lpr-fixpoint true`, the passes repeat as long as they keep making
   progress.

The prompt text is defined in the reducers, not in `LargeLanguageModel.kt`: the
shared system prompt and the output-format instructions (target list / whole
program) live in
[`AbstractLlmBasedReducer.kt`](src/org/perses/reduction/reducer/lpr/AbstractLlmBasedReducer.kt),
while each pass's primary and follow-up questions are defined in its subclass
(e.g.,
[`LlmBasedFunctionInliningReducer.kt`](src/org/perses/reduction/reducer/lpr/LlmBasedFunctionInliningReducer.kt)).
[`LargeLanguageModel.kt`](src/org/perses/reduction/reducer/lpr/LargeLanguageModel.kt)
assembles those pieces into the request message and parses the model's
responses.
