-- 코드를 입력하세요
SELECT ANIMAL_ID, NAME
from ANIMAL_OUTS
where ANIMAL_ID not in
(
    select ANIMAL_ID from ANIMAL_INS
)
order by ANIMAL_ID
