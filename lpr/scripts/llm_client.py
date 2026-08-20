#!/usr/bin/env python3

import sys
import argparse
import logging
import json
from openai import OpenAI

# Disable all logging below CRITICAL level
logging.basicConfig(level=logging.CRITICAL)

def main():
    parser = argparse.ArgumentParser(description="Call OpenAI-compatible LLM API for chat completion.")
    parser.add_argument("--base-url", type=str, default="http://localhost:11434/v1", help="Base URL of the LLM service")
    parser.add_argument("--api-key", type=str, default="ollama", help="API key for the LLM service")
    parser.add_argument("--model", type=str, default="codellama:13b", help="Model name to use")
    parser.add_argument("--temperature", type=float, default=1.0, help="Randomness of the output")
    parser.add_argument("--num-completions", type=int, default=5, help="Number of completions to return (default: 1)")
    parser.add_argument("--input-file", type=str, help="Path to the JSON file containing the input arguments")
    parser.add_argument("--output-file", type=str, help="Path to the JSON file where output will be saved")

    args = parser.parse_args()

    try:
        with open(args.input_file, "r") as file:
            data = json.load(file)

        message = data.get("message", "")

        # Prepare the messages for the OpenAI API
        messages = [{"role": "user", "content": message}]

        client = OpenAI(base_url=args.base_url, api_key=args.api_key)
        response = client.chat.completions.create(
            model=args.model,
            messages=messages,
            temperature=args.temperature,
            n=args.num_completions,
            stream=False,
            timeout=180.0,
        )
        # Collect all responses into a list
        results = [choice.message.content for choice in response.choices]
        with open(args.output_file, "w") as file:
            file.write(json.dumps(results))
    except Exception as e:
        err_message = f"Error: {e}"
        with open(args.output_file, "w") as file:
            file.write(err_message)
        print(err_message, file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    main()
