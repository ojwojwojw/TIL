select
    flavor
from
    (
        select
            fh.flavor,
            fh.total_order+jl.total_order,
            dense_rank() over(order by fh.total_order+jl.total_order desc) as rank
        from
            first_half fh,
            (
                select
                    flavor,
                    sum(total_order) as total_order
                from
                    july
                group by
                    flavor
             )jl
        where
            fh.flavor = jl.flavor   
    )
where 
    rank <4





