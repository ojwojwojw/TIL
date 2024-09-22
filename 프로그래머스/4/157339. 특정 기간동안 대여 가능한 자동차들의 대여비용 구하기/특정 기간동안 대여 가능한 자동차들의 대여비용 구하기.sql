select 
    c.car_id,
    c.car_type,
    c.daily_fee * 30 * (1 - p.discount_rate/100) as fee
from 
    car_rental_company_car c,
    car_rental_company_rental_history h,
    car_rental_company_discount_plan p
where
    c.car_id not in (
        select 
            car_id 
        from 
            car_rental_company_rental_history s_h
        where
            s_h.end_date > to_date('20221101','YYYYMMDD') 
            and s_h.start_date < to_date('20221201','YYYYMMDD')
    
    ) 
    and c.car_type = p.car_type
    and (c.car_type = '세단' or c.car_type = 'SUV')
    and p.duration_type ='30일 이상'
    
group by 
    c.car_id,
    c.car_type,
    c.daily_fee * 30 * (1 - p.discount_rate/100)
having 
    c.daily_fee * 30 * (1 - p.discount_rate/100) >= 500000 
    and c.daily_fee * 30 * (1 - p.discount_rate/100) < 2000000 

order by 
    fee desc,
    c.car_type asc ,
    c.car_id desc
    
