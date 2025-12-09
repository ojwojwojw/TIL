-- 코드를 입력하세요
SELECT
   B.CATEGORY as CATEGORY,
   SUM(BS.SALES) as TOTAL_SALES
FROM
    BOOK B,
    BOOK_SALES BS
WHERE 1=1
  and B.book_id = BS.book_id
  and BS.SALES_DATE >= '01-jan-22'
  and BS.sales_date < '01-feb-22'
GROUP BY B.CATEGORY
ORDER BY B.CATEGORY