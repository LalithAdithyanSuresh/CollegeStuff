// background.js

// Listen for messages from content script
chrome.runtime.onMessage.addListener(function(message, sender, sendResponse) {
    if (message.action === "htmlChanged") {
        console.log("HTML changed. Logging...");
        // Log the added <div> element
        console.log("Added <div>:", message.addedDiv);
        // Perform additional logging or storage operations here
    }
});
