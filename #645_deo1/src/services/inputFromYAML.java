package services;

import java.util.ArrayList;
import java.util.List;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;

import modules.PlumbingJob;
import org.yaml.snakeyaml.Yaml;

public class inputFromYAML {

    public static List<PlumbingJob> getData(String inputFile) throws FileNotFoundException {
        List<PlumbingJob> jobList = new ArrayList<PlumbingJob>();
        try (InputStream input = new FileInputStream(new File(inputFile));) {

            Yaml yaml = new Yaml();

            // The .loadAll(input) method returns an instance of Iterable<Object>,
            // where each object is of type List<PlumbingJob>
            for (Object data : yaml.loadAll(input)) {
                jobList = (List<PlumbingJob>) data;

            }

        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        return jobList;
    }
}
