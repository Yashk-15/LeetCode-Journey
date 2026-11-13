(SELECT u.name AS results
FROM Users u
JOIN MovieRating m ON m.user_id = u.user_id
GROUP BY u.user_id , u.name
ORDER BY COUNT(*) DESC, u.name
LIMIT 1
)
UNION ALL

(SELECT mv.title AS results
FROM Movies mv
JOIN MovieRating m
ON mv.movie_id = m.movie_id
WHERE m.created_at BETWEEN '2020-02-01' AND '2020-02-29'
GROUP BY mv.movie_id, mv.title
ORDER BY AVG(m.rating) DESC , mv.title
LIMIT 1
)