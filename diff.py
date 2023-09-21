import sys

def compare_files(file1, file2):
  """Compares the contents of two files line by line.

  Args:
    file1: The path to the first file.
    file2: The path to the second file.

  Returns:
    True if the two files are identical, False otherwise.
  """
  diff = []
  with open(file1, "r") as f1, open(file2, "r") as f2:
    for line1, line2 in zip(f1, f2):
      if line1 != line2:
        diff.append((line1.strip(), line2.strip()))
  return diff


if __name__ == "__main__":
  if len(sys.argv) != 3:
    print("Usage: compare_files.py <file1> <file2>")
    sys.exit(1)

  file1 = sys.argv[1]
  file2 = sys.argv[2]

  errors = compare_files(file1, file2)

  if ( len(errors) == 0):
    print("PERFECT MATCH")
  else:
    # print(errors)
    i=0
    print(f"{file1}\t{file2}")
    while(i < len(errors)):
        
        print(f"{errors[i][0]}\t\t{errors[i][1]}")
        i+=1