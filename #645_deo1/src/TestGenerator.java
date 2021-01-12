import modules.PlumbingJob;
import services.makeYAML;

import java.time.LocalDateTime;
import java.time.Period;
import java.util.*;
import java.io.IOException;
import java.util.concurrent.ThreadLocalRandom;

public class TestGenerator {

    public static void main(String[] args) throws IOException {
        String sep = System.getProperty("file.separator");
        String workingDir = System.getProperty("user.dir");
        String defaultFilePath = workingDir + sep + "resources" + sep + "generated_test1.yaml";
        Map<String, Integer> generatorParameters = getParametersFromUser();

        System.out.println("Generating file...");
        makeYAML.writeToYAML(generateJobs(generatorParameters.get("plumberNum"),
                             generatorParameters.get("jobsPerPlumber")),
                             defaultFilePath);
        System.out.println("YAML File "+ defaultFilePath + " generated");
    }

    private static List<PlumbingJob> generateJobs(int plumberNum, int jobsPerPlumber) {
        List<PlumbingJob> allJobs = new ArrayList<PlumbingJob>();
        LocalDateTime today = LocalDateTime.now();
        List<String> plumberIDs = new ArrayList<String>(10);
        for (int i = 0; i < plumberNum; i ++) {
            plumberIDs.add(generateRandomString(12, true));
        }

        String jobNum;
        String plumberID;
        long materialCost;
        long servicePrice;
        LocalDateTime serviceDateTime;
        String sDTstr;

        int jobAmount = plumberNum * jobsPerPlumber;

        for (int i = 0; i < jobAmount; i++) {
            jobNum = generateRandomString(5, false);
            plumberID = plumberIDs.get(i % 15);
            materialCost = ThreadLocalRandom.current().nextLong(1_000_000);
            servicePrice = ThreadLocalRandom.current().nextLong(1_000_000);
            serviceDateTime = today.minus(Period.ofDays(i));
            sDTstr = serviceDateTime.toString();

            allJobs.add(new PlumbingJob(jobNum, plumberID, materialCost, servicePrice, sDTstr));
        }

        return allJobs;
    }

    private static String generateRandomString(int length, boolean alphanumeric) {
        int leftLimit = 48; // numeral '0'
        int rightLimit;
        if (alphanumeric) {
            rightLimit = 122; // letter 'z'
        } else {
            rightLimit = 57; // numeral '9'
        }

        Random random = new Random();

        String generatedString = random.ints(leftLimit, rightLimit + 1)
                .filter(i -> (i <= 57 || i >= 65) && (i <= 90 || i >= 97))
                .limit(length)
                .collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append)
                .toString();

        return generatedString;
    }

    private static Map<String, Integer> getParametersFromUser() {
        Map<String, Integer> params = new HashMap<String, Integer>();

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of unique plumbers:");
        params.put("plumberNum", Integer.parseInt(sc.nextLine()));
        System.out.println("Enter number of jobs per plumber:");
        params.put("jobsPerPlumber", Integer.parseInt(sc.nextLine()));

        return params;
    }


}
