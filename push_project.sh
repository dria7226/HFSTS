cd HFSTS.wiki

cpp ./cpp/*.txt > ./*.md

if ! git diff-index --quiet HEAD --; then

git add .

id='date +%Y-%m-%d'

git commit -m "Auto - generated commit: $id"

git push

fi

cd ..
