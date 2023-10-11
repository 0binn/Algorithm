-- 코드를 입력하세요
SELECT p.PRODUCT_CODE, sum(p.PRICE*os.SALES_AMOUNT) as SALES
from PRODUCT as p
    join OFFLINE_SALE as os
    on p.PRODUCT_ID=os.PRODUCT_ID
group by p.PRODUCT_CODE
order by SALES desc, p.PRODUCT_CODE