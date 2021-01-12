package services;

import modules.PlumbingJob;
import org.yaml.snakeyaml.Yaml;

import java.io.*;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class makeYAML {

    public static List<PlumbingJob> userDataInput(){
        return getJobsFromConsole();
    }

    public static void writeToYAML(List<PlumbingJob> jobList, String filePath) throws IOException {
        Yaml yaml = new Yaml();
        File yamlFile = new File(filePath);
        boolean file_exists = yamlFile.exists();
        if (!file_exists) {
            try {
                file_exists = yamlFile.createNewFile();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        if (file_exists) {
            try (FileWriter fw
                         = new FileWriter(yamlFile)) {
                    yaml.dump(jobList, fw);
                }
            }

    }

    private static List<PlumbingJob> getJobsFromConsole() {
        List<PlumbingJob> newJobs = new ArrayList<PlumbingJob>();
        boolean more = false;

        while (newJobs.size() < 15 || !more) {
            PlumbingJob job = getJobFromUser();
            if (newJobs.size() > 15) {
                more = doYouWantMoreJobs();
            }
            newJobs.add(job);
        }
        return newJobs;
    }

    private static PlumbingJob getJobFromUser() {
        String jobNum = getJobNumFromUser();
        String plumberID = getPlumberIDFromUser();
        long materialCost = getMaterialCostFromUser();
        long servicePrice = getServicePriceFromUser();
        String serviceDateTime = getServiceDateTimeFromUser();

        return new PlumbingJob(jobNum, plumberID, materialCost, servicePrice, serviceDateTime);
    }

    private static String getJobNumFromUser() {
        String jobNum = "";
        System.out.println("Job number (ex. 01234):\n");
        Scanner sc = new Scanner(System.in);
        boolean valid = isJobNumberValid(jobNum);

        while (true) {
            jobNum = sc.nextLine();
            valid = isJobNumberValid(jobNum);
            if (valid) {
                break;
            }
            System.out.println("Invalid input, try again!\n");
        }
        return jobNum;
    }

    private static boolean isJobNumberValid(String jnIn) {
        Pattern jobNumPat = Pattern.compile("[0-9][0-9][0-9][0-9][0-9]");
        Matcher matcher = jobNumPat.matcher(jnIn);

        return matcher.find();
    }


    private static String getPlumberIDFromUser() {
        String plumberID = "";
        System.out.println("Plumber ID (ex. 0a1b3cdef647):\n");
        Scanner sc = new Scanner(System.in);
        boolean valid = isPlumberIDValid(plumberID);

        while (!valid) {
            plumberID = sc.nextLine();
            valid = isPlumberIDValid(plumberID);
            if (!valid) {
                System.out.println("Invalid input, try again!\n");
            }
        }
        return plumberID;
    }

    private static boolean isPlumberIDValid(String plumID) {
        Pattern jobNumPat = Pattern.compile("[a-zA-Z0-9][a-zA-Z0-9][a-zA-Z0-9][a-zA-Z0-9][a-zA-Z0-9][a-zA-Z0-9][a-zA-Z0-9][a-zA-Z0-9][a-zA-Z0-9][a-zA-Z0-9][a-zA-Z0-9][a-zA-Z0-9]");
        Matcher matcher = jobNumPat.matcher(plumID);
        return matcher.find();
    }

    private static long getMaterialCostFromUser() {
        System.out.println("Material cost (less or equal than 1,000,000):\n");
        return getCostFromUser();
    }

    private static long getServicePriceFromUser() {
        System.out.println("Material cost (less or equal than 1,000,000):\n");
        return getCostFromUser();
    }

    private static long getCostFromUser() {
        long cost = 0;

        Scanner sc = new Scanner(System.in);

        while (true) {
            cost = sc.nextLong();
            if (cost > 0 && cost <= 1_000_000) {
                break;
            }
            System.out.println("Invalid input, try again!\n");
        }

        return cost;
    }
    private static String getServiceDateTimeFromUser() {
        String serviceDT;
        String date;
        String time;
        String datetime;
        Scanner sc = new Scanner(System.in);
        System.out.println("Date (YYYY-MM-DD):\n");
        date = sc.nextLine();
        System.out.println("Time (HH:MM:SS)");
        time = sc.nextLine();
        datetime = date + "T" + time;
        serviceDT = datetime;
        return serviceDT;
    }

    private static boolean doYouWantMoreJobs() {
        boolean more = false;
        Scanner sc = new Scanner(System.in);
        String user_in = "";

        System.out.println("Do you want to add more jobs?(y\n)\n>>");
        user_in = sc.nextLine();
        more = isYes(user_in);
        return more;
    }

    private static boolean isYes(String in) {
        boolean flag = false;
        if (in.equals("y") || in.equals("Y") ||in.equals("yes") || in.equals("YES")) {
            flag = true;
        }
        return flag;
    }

    // public static YAMLFromConsole() {}
}
