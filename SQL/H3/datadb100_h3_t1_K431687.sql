-- Database basics 2021
-- H3 T1
-- anna.kleemola@tuni.fi

SELECT m.name, mov.name AS predecessor_name
FROM movie AS m, movie AS mov
WHERE m.predecessor_id = mov.id
ORDER BY m.id ASC;
