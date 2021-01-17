import modules.PlumberReport;
import modules.PlumbingJob;
import services.inputFromYAML;
import services.reportByMonth;
import services.outputToJSON;

import java.time.Month;
import java.util.List;
import java.io.FileNotFoundException;
import java.util.Map;


public class plumberYAMLToJSON {

    public static void main(String[] args) throws FileNotFoundException {
        String sep = System.getProperty("file.separator");
        String workingDir = System.getProperty("user.dir");
        String inputYAMLFilePath = workingDir + sep + "resources" + sep + "generated_test1.yaml";
        String outputJSONFile = workingDir + sep + "resources" + sep + "generated_test_out1.json";

        System.out.println("Loading "+ inputYAMLFilePath + " ...");
        List<PlumbingJob> yamlData = inputFromYAML.getData(inputYAMLFilePath);
        System.out.println("YAML File "+ inputYAMLFilePath + " loaded...");

        System.out.println("\nProcessing data...");
        Map<Month, List<PlumberReport>> serviceMonths = reportByMonth.getReportForAllMonths(yamlData);



        System.out.println("\nWriting to " + outputJSONFile + "...");
        outputToJSON.writeJSON(serviceMonths, outputJSONFile);


    }
}
