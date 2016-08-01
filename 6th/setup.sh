
#!/bin/sh

echo '' > ./day_$(date +%m%d).md
echo '[サイボウズ・ラボユース日時報告書]'
echo "勤務日：$(date '+%Y年%b%d日%a曜日')" >> ./day_$(date +%m%d).md
cat  template/day.md >> ./day_$(date +%m%d).md
cp template/report.txt .
