<?php
header('Content-Type: application/json');

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Get the raw POST data
    $rawData = file_get_contents('php://input');
    $data = json_decode($rawData, true);

    if (json_last_error() === JSON_ERROR_NONE) {
        // Convert the data array to JSON
        $jsonData = json_encode($data);

        // Write the JSON data to a local text file
        file_put_contents('data.txt', $jsonData);

        echo json_encode(["message" => "Data written to file successfully"]);
    } else {
        echo json_encode(["error" => "Invalid JSON data"]);
    }
} 

if ($_SERVER['REQUEST_METHOD'] === 'GET') {
    // Read the JSON data from the local text file
    if (file_exists('data.txt')) {
        $jsonData = file_get_contents('data.txt');

        // Decode the JSON data to an array
        $data = json_decode($jsonData, true);

        if (json_last_error() === JSON_ERROR_NONE) {
            echo json_encode($data);
        } else {
            echo json_encode(["error" => "Invalid JSON data in file"]);
        }
    } else {
        echo json_encode(["error" => "File not found"]);
    }
}
?>
