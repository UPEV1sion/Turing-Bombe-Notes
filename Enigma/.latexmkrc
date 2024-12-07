@default_excluded_files = ('latex_all_makros.tex');

$bibtex_use = 2;

$latex = 'pdflatex %O %S';  
$biber = 'biber %O %S';     

add_cus_dep('aux', 'bbl', 0, 'run_biber');
sub run_biber {
    system("biber $_[0]");
}

$pdflatex = 'pdflatex -interaction=nonstopmode -synctex=1 %O %S';
$pdf_mode = 1; 

$diagnostics = 1;

