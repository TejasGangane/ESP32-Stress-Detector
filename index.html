<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Stress Level Monitor</title>
    <style>
        body { font-family: Arial, sans-serif; text-align: center; margin-top: 50px; }
        button { padding: 10px 20px; font-size: 18px; cursor: pointer; }
        #output { margin-top: 20px; font-size: 20px; }
    </style>
</head>
<body>
    <h1>Stress Level Monitor</h1>
    <button onclick="startReading()">Start Readings</button>
    <div id="output"></div>

    <script>
        function startReading() {
            document.getElementById("output").innerHTML = "Collecting data...";
            
            fetch("/getSensorData")
                .then(response => {
                    if (!response.ok) {
                        throw new Error("Network response was not ok");
                    }
                    return response.json();
                })
                .then(data => {
                    document.getElementById("output").innerHTML = 
                        `Temperature: ${data.temperature}°F <br>
                         GSR: ${data.gsr} <br>
                         Predicted Stress Level: <strong>${data.stressLevel}</strong>`;
                })
                .catch(error => {
                    console.error("Error fetching data:", error);
                    document.getElementById("output").innerHTML = "⚠️ Error fetching data. Please try again!";
                });
        }
    </script>
</body>
</html>
