cd ./wiki_cpp
for filename in *.txt
do
    cpp $filename -P ../HFSTS.wiki/$(basename "$filename" .txt).md
done

cd ../HFSTS.wiki

git add .

git status

git commit -m "Auto-generated commit: `date +%Y-%m-%d:%H:%M`"

git push
