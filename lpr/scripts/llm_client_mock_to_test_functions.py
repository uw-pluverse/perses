#!/usr/bin/env python3

import argparse
import json

def main():

    parser = argparse.ArgumentParser(description="Call OpenAI-compatible LLM API for chat completion.")
    parser.add_argument("--input-file", type=str, help="Path to the JSON file containing the input arguments")
    parser.add_argument("--output-file", type=str, help="Path to the JSON file where output will be saved")

    args = parser.parse_args()

    with open(args.input_file, "r") as file:
        data = json.load(file)

    message = data.get("message", "")
    message_list = message.split("\n")

    results = []

    if message_list[0] == "succeed in the first time":
        results = [
            "result1: \n* a",
            "result2: \n* a\n* b",
        ]

    elif message_list[0] == "succeed in the second time":
        results = [
            "result1: \nwrong info",
            "result2: \n* a\n* b",
        ]
    elif message_list[0] == "succeed in the third time":
        results = [
            "result1: \nwrong info",
            "result2: \nwrong info\nxxxx",
            "result3: \n* a\n* b\n* c",
        ]
    elif message_list[0] == "never succeed":
        results = [
            "result1: \nwrong info",
            "result2: \nwrong info\nxxxx",
            "result3: \nvds\nrgvfdb\nsdlgsg",
        ]
    elif message_list[0] == "test other parameters":
        results = [
            f"* {message_list[0]}\n* {message_list[1]}\n* {message_list[2]}\n* {message_list[3]}"
        ]
    elif message_list[0] == "test get programs":
        responses = "\n".join(message_list[3:])
        results = responses.split("======")
    else:
        results = [message]

    with open(args.output_file, "w") as file:
        file.write(json.dumps(results))

if __name__ == "__main__":
    main()
