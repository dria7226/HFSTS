cd ./HFSTS.wiki_cpp

#generate cpp files for every core program according to core_programs.c

output_path="core_programs.txt"

cpp -P -D ENUMERATE -D NAME_MODE ../common_interpreter/core_programs.c > $output_path

program_code=0
IFS=','
while read line
do
    cp core_program_template.txt ../HFSTS.wiki/$line.txt
    sed -i 's/FILENAME/'$line'/g' ../HFSTS.wiki/$line.txt
    sed -i 's/program_code_code/'$program_code'/g' ../HFSTS.wiki/$line.txt
    let program_code=program_code+1
done < $output_path

rm $output_path

cd ../HFSTS.wiki

# preprocess generated operation files

for filename in *.txt
do
    cpp $filename -P $(basename "$filename" .txt).md
done

#push wiki to git
git add .

git status

git commit -m "Auto-generated commit: `date +%Y-%m-%d:%H:%M`"

git push
