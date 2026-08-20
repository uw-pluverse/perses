import unittest
import os
import shutil
import tempfile
import pandas as pd
from benchmark.plot_program_trend import plot_program_size_trends

class PlotProgramTrendTest(unittest.TestCase):
    def setUp(self):
        self.test_dir = tempfile.mkdtemp()
        self.csv_path = os.path.join(self.test_dir, "test.experiment.v1.csv")
        df = pd.DataFrame({
            'elapsed_seconds': [0, 10, 20, 30.5],
            'current_program_size': [100, 80, 60, 40]
        })
        df.to_csv(self.csv_path, index=False)

    def tearDown(self):
        shutil.rmtree(self.test_dir)

    def test_get_base_label(self):
        from benchmark.plot_program_trend import get_base_label
        self.assertEqual(get_base_label("test.csv"), "test")
        self.assertEqual(get_base_label("experiment.v1.csv"), "experiment")
        self.assertEqual(get_base_label("/path/to/data.json.csv"), "data")

    def test_format_legend_label(self):
        from benchmark.plot_program_trend import format_legend_label
        self.assertEqual(format_legend_label("mimir", 30.5, 40), "mimir (30.5s, 40)")
        self.assertEqual(format_legend_label("perses", 10.0, 100), "perses (10.0s, 100)")

    def test_plotting_dual_output(self):
        output_base = os.path.join(self.test_dir, "output")
        output_pdf = output_base + ".pdf"
        output_png = output_base + ".png"
        
        # Test function
        plot_program_size_trends(
            file_paths=[self.csv_path],
            labels=None,  # Should trigger default label generation
            output_path=output_pdf,
            xtick_count=10,
            fig_width=10,
            fig_height=10,
            y_max=None
        )
        
        # Verify both outputs exist
        self.assertTrue(os.path.exists(output_pdf), "PDF output missing")
        self.assertTrue(os.path.exists(output_png), "PNG output missing")

    def test_default_label_generation(self):
        # We can't easily inspect the legend content from the saved file without 
        # complex PDF/Image parsing, but we can verify the function runs without error
        # and check if it uses the correct path logic internally if we refactored.
        # For now, we'll verify it handles multiple files and generates both outputs.
        
        another_csv = os.path.join(self.test_dir, "another.data.csv")
        df = pd.DataFrame({
            'elapsed_seconds': [0, 5],
            'current_program_size': [10, 5]
        })
        df.to_csv(another_csv, index=False)
        
        output_path = os.path.join(self.test_dir, "multi_output.png")
        plot_program_size_trends(
            file_paths=[self.csv_path, another_csv],
            labels=None,
            output_path=output_path,
            xtick_count=5,
            fig_width=8,
            fig_height=8,
            y_max=100
        )
        
        self.assertTrue(os.path.exists(os.path.join(self.test_dir, "multi_output.png")))
        self.assertTrue(os.path.exists(os.path.join(self.test_dir, "multi_output.pdf")))

    def test_str2bool(self):
        from benchmark.plot_program_trend import str2bool
        import argparse
        self.assertTrue(str2bool("true"))
        self.assertTrue(str2bool("yes"))
        self.assertTrue(str2bool("1"))
        self.assertFalse(str2bool("false"))
        self.assertFalse(str2bool("no"))
        self.assertFalse(str2bool("0"))
        with self.assertRaises(argparse.ArgumentTypeError):
            str2bool("maybe")

    def test_sorting_logic(self):
        # Create CSVs with different last points
        # CSV 1: last_x=30, last_y=40
        csv1 = os.path.join(self.test_dir, "csv1.csv")
        pd.DataFrame({'elapsed_seconds': [0, 30], 'current_program_size': [100, 40]}).to_csv(csv1, index=False)
        
        # CSV 2: last_x=10, last_y=100 (Earlier time, should be first)
        csv2 = os.path.join(self.test_dir, "csv2.csv")
        pd.DataFrame({'elapsed_seconds': [0, 10], 'current_program_size': [100, 100]}).to_csv(csv2, index=False)
        
        # CSV 3: last_x=10, last_y=50 (Same time as CSV 2, smaller size, should be second)
        csv3 = os.path.join(self.test_dir, "csv3.csv")
        pd.DataFrame({'elapsed_seconds': [0, 10], 'current_program_size': [100, 50]}).to_csv(csv3, index=False)

        # We can't easily verify the plot, but we can call plot_program_size_trends
        # with these files and labels. To verify sorting, we'll need to mock plt.plot
        # or similar, but for a simple unit test, let's just ensure it runs.
        # To truly test sorting, I'll refactor a bit or use a mock.
        
        from unittest.mock import patch
        with patch('matplotlib.pyplot.plot') as mock_plot:
            plot_program_size_trends(
                file_paths=[csv1, csv2, csv3],
                labels=['L1', 'L2', 'L3'],
                output_path=os.path.join(self.test_dir, "sorted.png"),
                xtick_count=5,
                fig_width=8,
                fig_height=8,
                y_max=None,
                sort_plots=True
            )
            
            # Check the order of labels in mock_plot calls
            # Expected order: csv2 (time 10, size 100), then csv3 (time 10, size 50), then csv1 (time 30, size 40)
            # Wait, ascending order: 
            # 1. csv2 (10, 100) vs csv3 (10, 50) -> tie on time. Size ascending: csv3 (50) < csv2 (100).
            # So expected order: csv3, csv2, csv1.
            
            called_labels = [call.kwargs['label'] for call in mock_plot.call_args_list]
            self.assertEqual(len(called_labels), 3)
            self.assertIn("L3 (10s, 50)", called_labels[0])
            self.assertIn("L2 (10s, 100)", called_labels[1])
            self.assertIn("L1 (30s, 40)", called_labels[2])

if __name__ == "__main__":
    unittest.main()
