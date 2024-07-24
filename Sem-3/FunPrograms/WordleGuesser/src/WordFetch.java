import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;
import java.util.ArrayList;

public class WordFetch {
    public String[] Fetch() {
        String urlString = "https://raw.githubusercontent.com/charlesreid1/five-letter-words/master/sgb-words.txt"; // Replace with your URL

        ArrayList<String> wordsList = new ArrayList<>();

        try {
            URL url = new URL(urlString);
            BufferedReader br = new BufferedReader(new InputStreamReader(url.openStream()));

            String line;
            while ((line = br.readLine()) != null) {
                wordsList.add(line);
            }
            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

        // Convert ArrayList to array
        String[] wordsArray = wordsList.toArray(new String[0]);

        // Example of using the array
        return wordsArray;
    }
}


