cd ./HFSTS.wiki_cpp

#generate cpp files for every core program according to core/instructions.c

output_path="core_instructions.txt"

cpp -P -D NAME_MODE ../common_interpreter/core/instructions.c > $output_path

program_code=0

while read line
do
    cp core_program_template.txt ../HFSTS.wiki/$line.txt
    sed -i 's/FILENAME/'$line'/g' ../HFSTS.wiki/$line.txt
    sed -i 's/program_code_code/'$program_code'/g' ../HFSTS.wiki/$line.txt
    let program_code=program_code+1
    cpp ../HFSTS.wiki/$line.txt -P ../HFSTS.wiki/$line.md
    rm ../HFSTS.wiki/$line.txt
done < $output_path

rm $output_path

cd ../HFSTS.wiki
