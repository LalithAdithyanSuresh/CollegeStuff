<?php
header('Content-Type: application/json');

$input = json_decode(file_get_contents('php://input'), true);

$source_code = $input['source_code'];
$language_id = $input['language_id'];

$submission = [
    'source_code' => $source_code,
    'language_id' => $language_id,
    'stdin' => '',
    'expected_output' => '',
    'redirect_stderr_to_stdout' => true
];

$ch = curl_init();

curl_setopt($ch, CURLOPT_URL, 'http://localhost:2358/submissions/?base64_encoded=false&wait=true');
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
curl_setopt($ch, CURLOPT_POST, 1);
curl_setopt($ch, CURLOPT_POSTFIELDS, json_encode($submission));
curl_setopt($ch, CURLOPT_HTTPHEADER, [
    'Content-Type: application/json'
]);

$response = curl_exec($ch);

if (curl_errno($ch)) {
    echo json_encode(['error' => curl_error($ch)]);
} else {
    echo $response;
}

curl_close($ch);
?>
