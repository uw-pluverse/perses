import os
from posix import listdir

property_files = [os.path.join(os.getcwd(), f, "bug_descriptor.properties") for f in listdir(os.getcwd()) if not os.path.isfile(os.path.join(os.getcwd(), f)) ]

count = 0
for f_path in property_files:
    # print(f_path)
    count += 1
    try:
        os.rename(f_path, f_path+"_bak")
        with open(f_path+"_bak", 'r+') as f:
            with open(f_path, "w") as new_file:
                line = f.readline()
                while line:
                    new_file.write(line.replace("JavaScriptCrashDetector", "JerryScriptCrashDetector"))
                    line = f.readline()
    except Exception:
        pass
    print("Finished:", count, end="\r")
