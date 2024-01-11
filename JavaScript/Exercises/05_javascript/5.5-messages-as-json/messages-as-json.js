const template = document.getElementById("user-card-template");
const contacts = document.getElementById("contacts");

function parseJSON(event) {
    // Parse json data
    let data = JSON.parse(event.detail.jsonText);
    // Loop through each contact object and append it to the html
    data.forEach(contact => {
        const clone = template.content.cloneNode(true);
        clone.querySelector("img").src = contact.avatar;
        clone.querySelector("img").alt = contact.firstName + " " + contact.lastName;
        clone.querySelector("h1").textContent = contact.firstName + " " + contact.lastName;
        clone.querySelector("p.email").textContent = contact.email;
        clone.querySelector("p.phone > span").textContent = contact.phoneNumber;
        clone.querySelector("div.address").children[0].textContent = contact.address.streetAddress;
        clone.querySelector("div.address").children[1].textContent = contact.address.zipCode + " " + contact.address.city;
        clone.querySelector("div.address").children[2].textContent = contact.address.country;
        clone.querySelector("a").href = contact.homepage;
        clone.querySelector("a").textContent = contact.homepage;
        contacts.appendChild(clone);
    });  
}

// Add event listener for custom event
document.addEventListener("userDataReady", parseJSON);
fetchUserData();