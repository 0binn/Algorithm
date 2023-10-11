-- 코드를 입력하세요
SELECT hour(DATETIME) as HOUR, count(*) as count
from ANIMAL_OUTS
where hour(DATETIME) between 9 and 20
group by hour(DATETIME)
order by HOUR