
#!/bin/sh

echo '' > ./day_$(date +%m%d).md
echo "##$(date '+%b %d (%a) %Y')" >> ./day_$(date +%m%d).md
cat  template/day.md >> ./day_$(date +%m%d).md
cp template/report.txt .
