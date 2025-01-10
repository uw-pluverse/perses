![](https://github.com/chengniansun/kitten/workflows/CI/badge.svg)

# How to build Kitten

```bash
git clone git@github.com:chengniansun/perses-private.git
cd perses-private
git clone "your fork of perses-fuzzer"
bazel build kitten/src/org/perses/fuzzer:kira_deploy.jar
```

# How to run Kitten
1. Create a configuaration file, e.g.:
```bash
echo "language: "C"
seedFolders:
  - path: "seeds"
    fileExtentions: [".c"]
programsUnderTest: []
" > example-gcc-config.yaml
```
2. Put some seed files in the seed folder
3. Run kitten:
```bash
java -jar bazel-bin/kitten/src/org/perses/fuzzer/kira_deploy.jar \
  --testing-config example-gcc-config.yaml \
  --random-seed 0 \
  --timeout 1 \
  --max-recursions 5 \
  --enable-splicing true \
  --generator "RANDOM_GENERATOR" \
  --enable-deleting-on-random-positions true \
  --enable-deleting-on-continuous-positions true \
  --enable-inserting-on-random-positions true \
  --enable-inserting-on-continuous-positions true \
  --enable-replacing-on-random-positions true \
  --enable-replacing-on-continuous-positions true \
  --enable-replacing-identifier true \
  --enable-replacing-same-type-token true \
  --threads 1 \
  --verbosity "INFO" \
  --fuzzer-mode ONLY_GENERATE_MUTANTS
```

Check the flags that are supported by Kitten
```java -jar bazel-bin/kitten/src/org/perses/fuzzer/kira_deploy.jar --help```