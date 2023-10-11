-- 코드를 입력하세요
SELECT fh.FLAVOR from FIRST_HALF as fh join ICECREAM_INFO as ii on fh.FLAVOR = ii.FLAVOR
where TOTAL_ORDER>3000 and ii.INGREDIENT_TYPE='fruit_based'