import pandas
import argparse
from constants import name_mapping


# the following parameter is used in paper rcc
# # baseline
# baslines = ["SHA512", "STR", "ZIP", "CC", "RSTR"]
# # proj is the new algo that we proposed.
# proj = "RCCLIT"

# baseline
baslines = ["SHAFORMAT"]
# proj is the new algo that we proposed.
proj = "RCCFORMAT"

def main():
    df = pandas.read_csv(args.input_csv)
    df.rename(columns={'Environment': 'Cache'}, inplace=True)
    df = df.replace(name_mapping)
    df_avg = df.groupby(['Subject', 'Cache'], as_index=False).mean()
    df_avg = df_avg.sort_values(by=["Subject","Cache"])

    df_avg_time = df_avg[['Subject', 'Cache', 'Time']]
    df_avg_time = df_avg_time.set_index(['Subject', 'Cache']).Time.unstack().add_prefix('Cache_')

    for baseline in baslines:
        df_avg_time["relative_diff_{}_wrt_{}".format("RCC", baseline)] = ((
                                                            df_avg_time['Cache_{}'.format(baseline)]- df_avg_time['Cache_{}'.format(proj)])
                                                            /df_avg_time['Cache_{}'.format(baseline)] * 100)
    for baseline in baslines:
        df_avg_time["ratio_{}_wrt_{}".format("RCC", baseline)] = (df_avg_time['Cache_{}'.format(proj)]/df_avg_time['Cache_{}'.format(baseline)] * 100)


    if args.output_csv is None:
        df_avg_time.to_csv(args.input_csv + "_TIME.csv")
    else:
        df_avg_time.to_csv(args.output_csv)

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("-i", type=str, dest="input_csv", required=True, help="input csv file")
    parser.add_argument("-o", type=str, dest="output_csv", required=True, help="output csv file")

    args = parser.parse_args()
    main()
