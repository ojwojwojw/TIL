select
    to_number(to_char(car_rental_company_rental_history.start_date,'MM')) as month,
    car_rental_company_rental_history.car_id,
    count(car_rental_company_rental_history.car_id) as records
from
    car_rental_company_rental_history,
    (
        select 
            car_id,
            count(car_id) as record
        from 
            car_rental_company_rental_history 
        where
            start_date >= to_date('2022-08-01','YYYY-MM-DD') and
            start_date <  to_date('2022-11-01','YYYY-MM-DD') 
        group by 
            car_id
        having
            count(car_id) > 4
    )sub
where
    car_rental_company_rental_history.car_id = sub.car_id and
            
    start_date >= to_date('2022-08-01','YYYY-MM-DD') and 
    start_date <  to_date('2022-11-01','YYYY-MM-DD') 
group by
    car_rental_company_rental_history.car_id,
    to_char(car_rental_company_rental_history.start_date,'MM')
having
    count(car_rental_company_rental_history.car_id) > 0
order by 
    month asc,
    car_id desc