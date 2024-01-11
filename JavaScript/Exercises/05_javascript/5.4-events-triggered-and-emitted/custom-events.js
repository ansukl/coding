const dice = document.getElementById("roll-button");
const dieFace = document.getElementById("roll-button").querySelector('span');
const one = document.getElementById("ones").querySelector('p');
const two = document.getElementById("twos").querySelector('p');
const three = document.getElementById("threes").querySelector('p');
const four = document.getElementById("fours").querySelector('p');
const five = document.getElementById("fives").querySelector('p');
const six = document.getElementById("sixes").querySelector('p');
const total = document.getElementById("totals").querySelector('span');

const dieFaces = ['&#9856;', '&#9857;', '&#9858;', '&#9859;', '&#9860;', '&#9861;'];

dice.addEventListener("click", rollDice);


document.addEventListener('rollDice', function (event) {
    const dieValue = event.detail.value;
    dieFace.innerHTML = dieFaces[dieValue - 1];
    if (dieValue == 1) {
        const val = parseInt(one.innerHTML);
        if (val) {
            one.innerHTML = val + 1;
        } else {
            one.innerHTML = 1;
        }
    } else if (dieValue == 2) {
        const val = parseInt(two.innerHTML);
        if (val) {
            two.innerHTML = val + 1;
        } else {
            two.innerHTML = 1;
        }
    } else if (dieValue == 3) {
        const val = parseInt(three.innerHTML);
        if (val) {
            three.innerHTML = val + 1;
        } else {
            three.innerHTML = 1;
        }
    } else if (dieValue == 4) {
        const val = parseInt(four.innerHTML);
        if (val) {
            four.innerHTML = val + 1;
        } else {
            four.innerHTML = 1;
        }
    } else if (dieValue == 5) {
        const val = parseInt(five.innerHTML);
        if (val) {
            five.innerHTML = val + 1;
        } else {
            five.innerHTML = 1;
        }
    } else if (dieValue == 6) {
        const val = parseInt(six.innerHTML);
        if (val) {
            six.innerHTML = val + 1;
        } else {
            six.innerHTML = 1;
        }
    }

    total.innerHTML = parseInt(total.innerHTML) + 1;
});

