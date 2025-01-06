# script to convert "#include <...>" to "#include \"...\"" at files in "inc/"

import os
import re
import glob

for filename in glob.glob("inc/**", recursive=True):
  if not os.path.isfile(filename):
    continue
  with open(filename, "r", encoding="utf-8") as f:
    content = f.read()
  content = re.sub(r'#include <(.*?)>', r'#include "\1"', content)
  with open(filename, "w", encoding="utf-8") as f:
    f.write(content)
