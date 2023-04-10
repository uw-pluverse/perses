def proguard_strip(name, main_class, input_jar, output_jar):
    tool = "//third_party/proguard"
    log_file = "%s_log.txt" % name
    rt_file = "//third_party/proguard:rt_jar"
    args = [
        "$(location %s)" % tool,
        "-dontoptimize",
        "-dontobfuscate",
        # "-dontpreverify",
        "-dontwarn",
        "-keepclasseswithmembers '%s { public static void main(java.lang.String[]); }'" % main_class,
        "-libraryjars $(location %s)" % rt_file,
        "-injar $(location %s)" % input_jar,
        "-outjar $(location %s)" % output_jar,
        "> $(location %s) 2>&1" % log_file,
    ]
    native.genrule(
        name = name,
        outs = [
            output_jar,
            log_file,
        ],
        srcs = [
            input_jar,
            rt_file,
        ],
        tools = [
            tool,
        ],
        cmd = " ".join(args),
    )
