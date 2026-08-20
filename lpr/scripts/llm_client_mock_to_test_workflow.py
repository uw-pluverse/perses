#!/usr/bin/env python3

import argparse
import json
import textwrap

def remove_blanks(string):
    return "".join(char for char in string if not char.isspace())

def are_programs_same(p1, p2):
    return remove_blanks(p1) == remove_blanks(p2)

def main():

    parser = argparse.ArgumentParser(description="Call OpenAI-compatible LLM API for chat completion.")
    parser.add_argument("--input-file", type=str, help="Path to the JSON file containing the input arguments")
    parser.add_argument("--output-file", type=str, help="Path to the JSON file where output will be saved")

    args = parser.parse_args()

    with open(args.input_file, "r") as file:
        data = json.load(file)

    message = data.get("message", "")

    results = []

    # mock to test data type simplification
    program_input_data_type_simplification = textwrap.dedent("""\
    struct point {
      int x;
    };
    int main() {
      struct point p;
      p.x = 1;
      printf("%d", p.x);
      return 0;
    }""")
    program_output_data_type_simplification = textwrap.dedent("""\
    int main() {
      int x = 1;
      printf("%d", x);
      return 0;
    }""")

    # mock to test data type elimination
    program_input_data_type_elimination = textwrap.dedent("""\
    typedef int length;
    int main() {
      length x = 1;
      length y = x + 1;
      printf("%d", y);
      return 0;
    }""")
    program_output_data_type_elimination_optimal = textwrap.dedent("""\
    int main() {
      int x = 1;
      int y = x + 1;
      printf("%d", y);
      return 0;
    }""")
    program_output_data_type_elimination_suboptimal = textwrap.dedent("""\
    typedef int length;
    int main() {
      int x = 1;
      length y = x + 1;
      printf("%d", y);
      return 0;
    }""")

    # mock to test function inlining
    program_input_function_inlining = textwrap.dedent("""\
    int fn1() {
      return 1;
    }
    int fn2(int x) {
      return x + 1;
    }
    int main() {
      int a = fn1();
      a = fn2(a);
      printf("%d", a);
      return 0;
    }""")
    program_output_function_inlining_fn1_inlined = textwrap.dedent("""\
    int fn2(int x) {
      return x + 1;
    }
    int main() {
      int a = 1;
      a = fn2(a);
      printf("%d", a);
      return 0;
    }""")
    program_output_function_inlining_fn2_inlined = textwrap.dedent("""\
    int main() {
      int a = 1;
      a = a + 1;
      printf("%d", a);
      return 0;
    }""")

    # mock to test loop unrolling
    program_input_loop_unrolling = textwrap.dedent("""\
    int main() {
      int a = 1;
      for (int i = 0; i < 3; i++) {
        a = a + 1;
      }
      printf("%d", a);
      return 0;
    }""")
    program_output_loop_unrolling = textwrap.dedent("""\
    int main() {
      int a = 1;
      a = a + 1;
      a = a + 1;
      a = a + 1;
      printf("%d", a);
      return 0;
    }""")

    # mock to test variable elimination
    program_input_variable_elimination = textwrap.dedent("""\
    int main() {
      int a = 1;
      printf("%d", a);
      return 0;
    }""")
    program_output_variable_elimination = textwrap.dedent("""\
    int main() {
      printf("%d", 1);
      return 0;
    }""")

    # mock the whole system test
    program_input_function_inlining_system_test = textwrap.dedent("""\
    #include <stdio.h>
    typedef int length;
    length b[100];
    int init() {
      return 100;
    }
    int main() {
      length a = init();
      for (int i = 0; i < 10; i++)
        b[i] = a - i;
      printf("%d", b[6]);
    }""")
    program_output_function_inlining_system_test = textwrap.dedent("""\
    #include <stdio.h>
    typedef int length;
    length b[100];
    int main() {
      length a = 100;
      for (int i = 0; i < 10; i++)
        b[i] = a - i;
      printf("%d", b[6]);
    }""")
    program_input_loop_unrolling_system_test = textwrap.dedent("""\
    #include <stdio.h>
    typedef int length;
    length b[100];
    int main() {
      length a = 100;
      for (int i = 0; i < 10; i++)
        b[i] = a - i;
      printf("%d", b[6]);
    }""")
    program_output_loop_unrolling_system_test = textwrap.dedent("""\
    #include <stdio.h>
    typedef int length;
    length b[100];
    int main() {
      length a = 100;
      b[0] = a - 0;
      b[1] = a - 1;
      b[2] = a - 2;
      b[3] = a - 3;
      b[4] = a - 4;
      b[5] = a - 5;
      b[6] = a - 6;
      b[7] = a - 7;
      b[8] = a - 8;
      b[9] = a - 9;
      printf("%d", b[6]);
    }""")
    program_input_data_type_elimination_system_test = textwrap.dedent("""\
    #include <stdio.h>
    typedef int length;
    length b[100];
    int main() {
      length a = 100;
    
    
    
    
    
    
      b[6] = a - 6;
    
    
    
      printf("%d", b[6]);
    }""")
    program_output_data_type_elimination_system_test = textwrap.dedent("""\
    #include <stdio.h>
    typedef int length;
    int b[100];
    int main() {
      int a = 100;
      b[6] = a - 6;
      printf("%d", b[6]);
    }""")
    program_input_data_type_simplification_system_test = textwrap.dedent("""\
    #include <stdio.h>
    
    int b[100];
    int main() {
      int a = 100;
      b[6] = a - 6;
      printf("%d", b[6]);
    }""")
    program_output_data_type_simplification_system_test = textwrap.dedent("""\
    #include <stdio.h>
    int b;
    int main() {
      int a = 100;
      b = a - 6;
      printf("%d", b);
    }""")
    program_input_variable_elimination_system_test_target_a = textwrap.dedent("""\
    #include <stdio.h>
    int b;
    int main() {
      int a = 100;
      b = a - 6;
      printf("%d", b);
    }""")
    program_input_variable_elimination_system_test_target_b = textwrap.dedent("""\
    #include <stdio.h>
    int b;
    int main() {
      b = 100 - 6;
      printf("%d", b);
    }""")
    program_output_variable_elimination_system_test_target_b = textwrap.dedent("""\
    #include <stdio.h>
    int main() {
      printf("%d", 94);
    }""")

    # mock to test the system cache the global minimal result and rollback
    program_input_loop_unrolling_system_test_rollback = textwrap.dedent("""\
    #include <stdio.h>
    int main() {
      int a = 1;
      for (int i = 0; i < 10; i++)
        a = a + 1;
      printf("%d", a);
    }""")
    program_output_loop_unrolling_system_test_rollback = textwrap.dedent("""\
    #include <stdio.h>
    int main() {
      int a = 1;
      a = a + 1;
      a = a + 1;
      a = a + 1;
      a = a + 1;
      a = a + 1;
      a = a + 1;
      a = a + 1;
      a = a + 1;
      a = a + 1;
      a = a + 1;
      printf("%d", a);
    }""")

    program = message.split("The program: ")[-1].strip()

    # primary question
    if "Please generate analysis and the target list" in message:
        if are_programs_same(program, program_input_data_type_simplification):
            results = [
                "result1: \n* point"
            ]

        if are_programs_same(program, program_input_data_type_elimination):
            results = [
                "result1: \n* length"
            ]

        if are_programs_same(program, program_input_function_inlining):
            results = [
                "result1: \n* fn1\n* fn2"
            ]

        if are_programs_same(program, program_input_loop_unrolling):
            results = [
                "result1: \n* for (int i = 0; i < 3; i++)"
            ]
        if are_programs_same(program, program_input_variable_elimination):
            results = [
                "result1: \n* a"
            ]
        if are_programs_same(program, program_input_function_inlining_system_test) and "identify all functions" in message:
            results = [
                "result1: \n* init"
            ]
        if are_programs_same(program, program_input_loop_unrolling_system_test) and "identify all loop structures" in message:
            results = [
                "result1: \n* for (int i = 0; i < 10; i++)"
            ]
        if (are_programs_same(program, program_input_data_type_elimination_system_test)
                and "identify all redundant data types" in message):
            results = [
                "result1: \n* length"
            ]
        if (are_programs_same(program, program_input_data_type_simplification_system_test)
                and "identify all variables with complex data types" in message):
            results = [
                "result1: \n* b[100]"
            ]
        if (are_programs_same(program, program_input_variable_elimination_system_test_target_a)
                and "identify all intermediate or unused variables" in message):
            results = [
                "result1: \n* a\n* b"
            ]

        if are_programs_same(program, program_input_loop_unrolling_system_test_rollback) and "identify all loop structures" in message:
            results = [
                "result1: \n* for (int i = 0; i < 10; i++)"
            ]

    # followup question
    if "Please generate analysis and the whole program" in message:
        if are_programs_same(program, program_input_data_type_simplification):
            results = [
                "result1:\n"
                + "```c\n"
                + program_output_data_type_simplification + "\n"
                + "```"
            ]
        if are_programs_same(program, program_input_data_type_elimination):
            results = [
                "result1:\n"
                + "```c\n"
                + program_output_data_type_elimination_suboptimal + "\n"
                + "```",
                "result2:\n"
                + "```c\n"
                + "wrong code\n"
                + "```",
                "result3:\n"
                + "```c\n"
                + program_output_data_type_elimination_optimal + "\n"
                + "```",
            ]
        if are_programs_same(program, program_input_function_inlining):
            results = [
                "result1:\n"
                + "```c\n"
                + program_output_function_inlining_fn1_inlined + "\n"
                + "```"
            ]
        if are_programs_same(program, program_output_function_inlining_fn1_inlined):
            results = [
                "result1:\n"
                + "```c\n"
                + program_output_function_inlining_fn2_inlined + "\n"
                + "```"
            ]
        if are_programs_same(program, program_output_function_inlining_fn1_inlined):
            results = [
                "result1:\n"
                + "```c\n"
                + program_output_function_inlining_fn2_inlined + "\n"
                + "```"
            ]
        if are_programs_same(program, program_input_loop_unrolling):
            results = [
                "result1:\n"
                + "```c\n"
                + program_output_loop_unrolling + "\n"
                + "```"
            ]
        if are_programs_same(program, program_input_variable_elimination):
            results = [
                "result1:\n"
                + "```c\n"
                + program_output_variable_elimination + "\n"
                + "```"
            ]
        if are_programs_same(program, program_input_function_inlining_system_test):
            results = [
                "result1:\n"
                + "```c\n"
                + program_output_function_inlining_system_test + "\n"
                + "```"
            ]
        if are_programs_same(program, program_input_loop_unrolling_system_test):
            results = [
                "result1:\n"
                + "```c\n"
                + program_output_loop_unrolling_system_test + "\n"
                + "```"
            ]
        if are_programs_same(program, program_input_data_type_elimination_system_test):
            results = [
                "result1:\n"
                + "```c\n"
                + program_output_data_type_elimination_system_test + "\n"
                + "```"
            ]
        if are_programs_same(program, program_input_data_type_simplification_system_test):
            results = [
                "result1:\n"
                + "```c\n"
                + program_output_data_type_simplification_system_test + "\n"
                + "```"
            ]
        if are_programs_same(program, program_input_variable_elimination_system_test_target_a):
            results = [
                "result1:\n"
                + "```c\n"
                + program_input_variable_elimination_system_test_target_b + "\n"
                + "```"
            ]
        if are_programs_same(program, program_input_variable_elimination_system_test_target_b):
            results = [
                "result1:\n"
                + "```c\n"
                + program_output_variable_elimination_system_test_target_b + "\n"
                + "```"
            ]

        if are_programs_same(program, program_input_loop_unrolling_system_test_rollback):
            results = [
                "result1:\n"
                + "```c\n"
                + program_output_loop_unrolling_system_test_rollback + "\n"
                + "```"
            ]

    with open(args.output_file, "w") as file:
        file.write(json.dumps(results))

if __name__ == "__main__":
    main()
