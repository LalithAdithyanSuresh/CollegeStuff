document.getElementById('codeForm').addEventListener('submit', async function(event) {
    event.preventDefault();

    const language = document.getElementById('language').value;
    const code = document.getElementById('code').value;
    const outputElement = document.getElementById('output');

    try {
        const response = await fetch('execute.php', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({
                language_id: language,
                source_code: code
            })
        });

        const data = await response.json();
        outputElement.textContent = data.stdout || data.stderr || 'Error executing code';
    } catch (error) {
        outputElement.textContent = 'Error: ' + error.message;
    }
});
