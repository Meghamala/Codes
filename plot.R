install.packages("rpart")
library(rpart)
install.packages("partykit")
library(partykit)
data <- read.table("record1.csv")
names(data) <- c("gender","cartype","size","class")
adm_data <- as.data.frame(data)
tree1 <- rpart(class ~ gender + cartype + size,data <- adm_data)
plot(as.party(tree1 ))



