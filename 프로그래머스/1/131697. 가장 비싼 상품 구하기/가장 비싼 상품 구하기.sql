select
    max(price) as max_price
from
    product
order by
    price desc
