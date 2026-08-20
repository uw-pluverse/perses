# How to Run an XML Benchmark

### Run r.sh
Take `xml-071d221-1` as an example.
```
cd xml-071d221-1
XML_JAR_DIR="$(pwd)/../lib" ./r.sh
```

### Run a benchmark
Take `xml-071d221-1` as an example.
```bash
cd xml-071d221-1
# build perses
bazelisk build //src/org/perses:perses_deploy.jar
# run perses
XML_JAR_DIR="$(pwd)/../lib" java -jar "$(bazelisk info bazel-bin)/src/org/perses/perses_deploy.jar" \
--test-script r.sh \
--input-file input.xml \
--output-dir ./output
```