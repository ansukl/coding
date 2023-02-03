
--Ice cream manufacturers
INSERT INTO manufacturer VALUES (
    1, 'Jen & Berry', 'Canada'
);

INSERT INTO manufacturer VALUES (
    2, '4 Friends', 'Finland'
);

INSERT INTO manufacturer VALUES (
    3, 'Gelatron', 'Italy'
);

--Ice cream

INSERT INTO ice_cream VALUES (
    1, 'Plain Vanilla', 1, 1.00
);

INSERT INTO ice_cream VALUES (
    2, 'Vegan Vanilla', 2, 0.89
);

INSERT INTO ice_cream VALUES (
    3, 'Super Strawberry', 2, 1.44
);

INSERT INTO ice_cream VALUES (
    4, 'Very plain', 2, 1.20
);


--Ingredients
INSERT INTO ingredient VALUES (
    1, 'Cream', 400, 3, 0
);

INSERT INTO ingredient VALUES (
    2, 'Coconut cream', 230, 2.3, 1
);

INSERT INTO ingredient VALUES (
    3, 'Sugar', 387, 0, 1
);

INSERT INTO ingredient VALUES (
    4, 'Vanilla extract', 12, 0, 1
);


INSERT INTO ingredient VALUES (
    5, 'Strawberry', 33, 0.7, 1
);

INSERT INTO ingredient VALUES (
    6, 'Dark chocolate', 535, 8, 1
);


--Contains

INSERT INTO contains VALUES ( 
    1, 1, 70
);
INSERT INTO contains VALUES ( 
    1, 3, 27
);
INSERT INTO contains VALUES ( 
    1, 4, 3
);


INSERT INTO contains VALUES ( 
    2, 2, 74
);
INSERT INTO contains VALUES ( 
    2, 3, 21
);
INSERT INTO contains VALUES ( 
    2, 4, 5
);

INSERT INTO contains VALUES ( 
    3, 1, 60
);
INSERT INTO contains VALUES ( 
    3, 3, 10
);
INSERT INTO contains VALUES ( 
    3, 5, 30
);


INSERT INTO contains VALUES ( 
    4, 2, 95
);
INSERT INTO contains VALUES ( 
    4, 4, 5
);

