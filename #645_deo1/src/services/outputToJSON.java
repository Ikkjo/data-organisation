package services;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.SerializationFeature;
import modules.PlumberReport;

import java.util.List;
import java.io.File;
import java.io.IOException;
import java.time.Month;
import java.util.Map;

public class outputToJSON {

    public static void writeJSON(Map<Month, List<PlumberReport>> jsonData, String filePath) {
        ObjectMapper mapper = new ObjectMapper();

        File outJSONFile = new File(filePath);

        try {
            mapper.enable(SerializationFeature.INDENT_OUTPUT);
            mapper.writeValue(outJSONFile, jsonData);
            System.out.println("Writing to JSON successful!");
        } catch (IOException e) {
            System.out.println("Error, could write to output file!");
        }
    }

}
