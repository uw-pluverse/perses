#!/usr/bin/env python3

import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import argparse
import sys
import os
import glob

def str2bool(v):
    if isinstance(v, bool):
        return v
    if v.lower() in ('yes', 'true', 't', 'y', '1'):
        return True
    elif v.lower() in ('no', 'false', 'f', 'n', '0'):
        return False
    else:
        raise argparse.ArgumentTypeError('Boolean value expected.')

def get_base_label(path):
    """Returns the prefix before the first dot in the filename."""
    return os.path.basename(path).split('.')[0]

def format_legend_label(label, last_x, last_y):
    """Formats the legend label with time and size suffixes."""
    return f"{label} ({last_x}s, {int(last_y)})"

def plot_program_size_trends(file_paths, labels, output_path, xtick_count, fig_width, fig_height, y_max, sort_plots=False):
    """
    Plots trends from multiple CSV files with customizable dimensions and labels.
    """
    try:
        # Check if number of labels matches number of files
        if labels and len(labels) != len(file_paths):
            print(f"Error: Provided {len(file_paths)} files but {len(labels)} labels.")
            sys.exit(1)

        if not file_paths:
            print("Error: No CSV files found to plot.")
            return

        # Default labels if none provided
        if not labels:
            labels = [get_base_label(path) for path in file_paths]

        # Set the figure size (Width, Height) in inches
        plt.figure(figsize=(fig_width, fig_height))

        # Distinct line styles, markers, and colors
        styles = ['-', '--', '-.', ':']
        markers = ['o', 's', '^', 'v', 'D', '*', 'p', 'h', '8']
        colors = plt.cm.tab10.colors

        # Prepare data for plotting
        plot_data = []
        for i, path in enumerate(file_paths):
            try:
                df = pd.read_csv(path)
                # Validation for columns
                if 'elapsed_seconds' not in df.columns or 'current_program_size' not in df.columns:
                    print(f"Error: {path} is missing required columns.")
                    continue
                
                last_x = df['elapsed_seconds'].iloc[-1] if not df.empty else 0
                last_y = df['current_program_size'].iloc[-1] if not df.empty else 0
                label = labels[i]
                if not df.empty:
                    label = format_legend_label(label, last_x, last_y)
                
                plot_data.append({
                    'df': df,
                    'label': label,
                    'last_x': last_x,
                    'last_y': last_y,
                    'path_index': i
                })
            except Exception as e:
                print(f"Error reading/parsing {path}: {e}")
                continue

        if sort_plots:
            # Sort by last_x (time) ascending, then last_y (size) ascending
            plot_data.sort(key=lambda x: (x['last_x'], x['last_y']))

        for i, entry in enumerate(plot_data):
            df = entry['df']
            full_label = entry['label']
            orig_idx = entry['path_index']

            plt.plot(df['elapsed_seconds'], df['current_program_size'],
                     label=full_label,
                     linewidth=1,
                     marker=markers[orig_idx % len(markers)],
                     markevery=0.1,  # Place markers at 10% intervals of the data
                     color=colors[orig_idx % len(colors)],
                     linestyle=styles[orig_idx % len(styles)])

        # Labels and appearance
        plt.xlabel('Time (seconds)')
        plt.ylabel('Program Size (tokens)')
        plt.title('Program Size Reduction Trend')
        plt.margins(x=0.05, y=0.1)
        
        # Y-axis limit logic
        if y_max:
            plt.ylim(top=y_max)

        plt.legend()
        plt.grid(True, linestyle=':', alpha=0.6)

        # X-axis granularity (number of ticks)
        ax = plt.gca()
        ax.xaxis.set_major_locator(ticker.MaxNLocator(nbins=xtick_count))
        plt.xticks(rotation=45)

        # Save in two formats (PNG and PDF)
        base = os.path.splitext(output_path)[0]
        
        target_formats = ['.pdf', '.png']
        for target_ext in target_formats:
            save_path = f"{base}{target_ext}"
            plt.savefig(save_path, bbox_inches='tight')
            print(f"Successfully saved plot to: {save_path}")

    except Exception as e:
        print(f"An error occurred: {e}")
        sys.exit(1)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Plot trends from multiple CSV files.")

    # Required Arguments
    parser.add_argument("--files", nargs='+', required=True, help="Input CSV files or directories containing CSV files")
    parser.add_argument("--output", required=True, help="Output file path (e.g., plot.pdf)")

    # Optional Customization
    parser.add_argument("--labels", nargs='+', help="Legend names for the files")
    parser.add_argument("--xticks", type=int, default=20, help="Number of ticks on X-axis")
    parser.add_argument("--width", type=float, default=12.0, help="Width of the figure in inches")
    parser.add_argument("--height", type=float, default=12.0, help="Height of the figure in inches")
    parser.add_argument("--ymax", type=float, help="Max value for Y-axis")
    parser.add_argument("--sort-plots", type=str2bool, default=True, help="Sort plots in the legend by their last point time and then size (true/false)")

    args = parser.parse_args()

    if args.files:
        resolved_files = []
        for f in args.files:
            if os.path.isdir(f):
                # Glob all .csv files in the directory
                csv_files = glob.glob(os.path.join(f, "*.csv"))
                # Sort them for deterministic order
                csv_files.sort()
                resolved_files.extend(csv_files)
            else:
                resolved_files.append(f)
        args.files = resolved_files

    plot_program_size_trends(
        args.files,
        args.labels,
        args.output,
        args.xticks,
        args.width,
        args.height,
        args.ymax,
        args.sort_plots
    )