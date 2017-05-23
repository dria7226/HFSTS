cd ./wiki_cpp

#generate cpp files for every core program according to core_programs.c

output_path="core_programs.txt"

cpp -P -D ENUMERATE -D NAME_MODE ../common_interpreter/core_programs.c > $output_path

program_code=0
IFS=','
while read line
do
    cp core_program_template.txt $line.txt
    sed -i 's/FILENAME/'$line'/g' $line.txt
    sed -i 's/program_code_code/'$program_code'/g'
    $(program_code)=$(program_code)+1
    echo $line
    echo $operation_code
done < $output_path

rm $output_path

# preprocess generated operation files

for filename in *.txt
do
    cpp $filename -P ../HFSTS.wiki/$(basename "$filename" .txt).md
done

#push wiki to git
cd ../HFSTS.wiki

#git add .

#git status

#git commit -m "Auto-generated commit: `date +%Y-%m-%d:%H:%M`"

#git push
