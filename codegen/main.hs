module Main (main) where
import System.FilePath

dataDirectory :: FilePath
dataDirectory = "../data"

getTableDataPath :: String -> FilePath
getTableDataPath tableName = combine dataDirectory fileName
	where fileName = addExtension ("table-" ++ tableName) "txt"

main = do
  s <- readFile (getTableDataPath "head")
  putStrLn s
