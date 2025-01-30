SELECT   
    AB.HISTORY_ID,
    CASE 
        WHEN AB.test = 'case1'  THEN AB.DAILY_FEE * AB.DURATION
        ELSE AB.DAILY_FEE * AB.DURATION * (100 - AB.DISCOUNT_RATE) * 0.01
    END AS FEE
FROM
(
    SELECT
        CRC.DAILY_FEE,
        A.HISTORY_ID,
        A.START_DATE,
        A.END_DATE,
        A.END_DATE - A.START_DATE + 1 AS DURATION,
        CASE
            WHEN A.END_DATE - A.START_DATE + 1 < 7 
                THEN 'case1'
            WHEN A.END_DATE - A.START_DATE + 1 >= 7 AND A.END_DATE - A.START_DATE + 1 < 30
                THEN 'case2'
            WHEN A.END_DATE - A.START_DATE + 1 >= 30 AND A.END_DATE - A.START_DATE + 1 < 90
                THEN 'case3'
            WHEN A.END_DATE - A.START_DATE + 1 >= 90 
                THEN 'case4'
        END AS TEST,
        B.DISCOUNT_RATE
    FROM
        CAR_RENTAL_COMPANY_CAR CRC,
        (
            SELECT
                CRC.CAR_ID,
                CRH.HISTORY_ID,
                CRH.START_DATE,
                CRH.END_DATE
            FROM
                CAR_RENTAL_COMPANY_CAR CRC,
                CAR_RENTAL_COMPANY_RENTAL_HISTORY CRH
            WHERE 1=1
                AND CRC.CAR_ID = CRH.CAR_ID
        ) A,
        (
            SELECT
                *
            FROM
                CAR_RENTAL_COMPANY_DISCOUNT_PLAN CDP
            WHERE 1=1
                AND CDP.CAR_TYPE = '트럭'
        ) B
    WHERE 1=1
        AND CRC.CAR_ID = A.CAR_ID (+)
        AND CRC.CAR_TYPE = B.CAR_TYPE 
        AND CRC.CAR_TYPE = '트럭'
    ) AB
WHERE  1=1
    AND (
            (AB.TEST = 'case1' AND AB.DISCOUNT_RATE = 5)
            OR(AB.TEST = 'case2' AND AB.DISCOUNT_RATE = 5)
            OR(AB.TEST = 'case3' AND AB.DISCOUNT_RATE = 8)
            OR(AB.TEST = 'case4' AND AB.DISCOUNT_RATE = 15)
        )
ORDER BY
    FEE DESC,
    HISTORY_ID DESC
;