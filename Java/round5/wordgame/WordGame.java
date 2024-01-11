/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author annak
 */
import java.io.BufferedReader;
import java.util.ArrayList;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.io.IOException;

public class WordGame {

    private ArrayList<String> words = new ArrayList<>();
    private WordGameState state = null;
    private boolean active = false;
    
    public static class WordGameState {
        private String word_correct;
        private String word;
        private int mistakes;
        private int max_mistakes;
        private int unknown_chars;
        private ArrayList<Character> guessed_chars = new ArrayList<>();
        
        private WordGameState(String word, int max_mistakes) {
            this.word_correct = word;
            this.max_mistakes = max_mistakes;
            this.unknown_chars = word.length();
            this.mistakes = 0;
            this.word = "_".repeat(word.length());
        }
        
        public String getWord() {
            return this.word;
        }
        
        public int getMistakes() {
            return this.mistakes;
        }
        
        public int getMistakeLimit() {
            return this.max_mistakes;
        }
        
        public int getMissingChars() {
            return this.unknown_chars;
        }
    }
    
    public WordGame(String wordFilename) {
        try {
            FileInputStream fstream = new FileInputStream(wordFilename);
            BufferedReader br = new BufferedReader(new InputStreamReader(fstream));

            String strLine;

            while ((strLine = br.readLine()) != null)   {
              //System.out.println (strLine);
              words.add(strLine);
            }
            
            fstream.close();   
        }
        
        catch (FileNotFoundException e) {
            System.out.println (e);
        }
        catch (IOException e) {
            System.out.println (e);
        }
    }
    
    public void initGame(int wordIndex, int mistakeLimit) {
        int index = wordIndex % words.size();
        state = new WordGameState(words.get(index), mistakeLimit);
        active = true;
    }
    
    public boolean isGameActive() {
        return active;
    }
    
    public WordGameState getGameState() throws GameStateException {
        if (!active) {
            throw new GameStateException("There is currently no active word game!");
        }
        return state;
    }
    
    public WordGameState guess(char c) throws GameStateException {
        if (!active) {
            throw new GameStateException("There is currently no active word game!");
        }
        
        c = Character.toLowerCase(c);
        
        if (state.guessed_chars.contains(c)) {
            state.mistakes += 1;
            return state;
        }
        
        state.guessed_chars.add(c);
        boolean found = false;
        StringBuilder new_word = new StringBuilder(state.word);
        int index = state.word_correct.indexOf(c);
        while (index >= 0) {
            new_word.setCharAt(index, c);
            index = state.word_correct.indexOf(c, index + 1);
            state.unknown_chars -= 1;
            found = true;
        }
        
        if (!found) {
            state.mistakes += 1;
            if (state.mistakes > state.max_mistakes) {
                state.word = state.word_correct;
                active = false;
            }
        }
        
        else {
            state.word = new_word.toString();
            if (state.unknown_chars == 0) {
                active = false;
            }
        }
        
        return state;
    }
    
    public WordGameState guess(String word) throws GameStateException {
        if (!active) {
            throw new GameStateException("There is currently no active word game!");
        }
        
        if (word.equals(state.word_correct)) {
            state.unknown_chars = 0;
            state.word = state.word_correct;
            active = false;
        }
        else {
            state.mistakes += 1;
            if (state.mistakes > state.max_mistakes) {
                state.word = state.word_correct;
                active = false;
            }
        }
        return state;
    }
}
