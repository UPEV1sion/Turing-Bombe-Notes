def format_output(char):
    print(f"\\texttt{{{char}}} & ", end="");
    
ciphertext = "BHNCXSEQKOBIIODWFBTZGCYEHQQJ"
crib = "OBERKOMMANDODERWEHRMACHT"

for c in ciphertext:
    format_output(c)
    
for c in crib:
    format_output(c)
