import pandas as pd
import numpy as np
from sklearn.linear_model import LogisticRegression
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
from sklearn.model_selection import cross_val_score
from sklearn.metrics import accuracy_score
from sklearn.model_selection import RandomizedSearchCV
import joblib

# open the file
data = pd.read_csv("LoanApprovalPrediction.csv")

# fill the missing value
data = data.drop('Loan_ID', axis = 1)
column = ['Gender','Dependents','LoanAmount','Loan_Amount_Term']
data = data.dropna(subset=column)
data['Credit_History'] = data['Credit_History'].fillna(data['Credit_History'].mode()[0])
# Convert str or obj to int and float
data['Gender'] = data['Gender'].map({'Male':1,'Female':0}).astype('int')
data['Married'] = data['Married'].map({'Yes':1,'No':0}).astype('int')
data['Education'] = data['Education'].map({'Graduate':1,'Not Graduate':0}).astype('int')
data['Self_Employed'] = data['Self_Employed'].map({'Yes':1,'No':0}).astype('int')
data['Property_Area'] = data['Property_Area'].map({'Rural':0,'Urban':1,'Semiurban':2}).astype('int')
data['Loan_Status'] = data['Loan_Status'].map({'Y':1,'N':0}).astype('int')


# Store a matric X and vector y
X = data.drop('Loan_Status', axis = 1)
y = data['Loan_Status']


# Scalling
cols = ['ApplicantIncome','CoapplicantIncome','LoanAmount','Loan_Amount_Term']
st = StandardScaler()
X[cols]= st.fit_transform(X[cols])


# Trainning set data
model_df = {}
def model_value(model, X, y):
  X_train, X_test, y_train, y_test = train_test_split(X,y,test_size = 0.2, random_state = 42)
  model.fit(X_train,y_train)
  y_pred = model.predict(X_test)
  print(f"{model} accuarcy is {accuracy_score(y_test,y_pred)}")
  score = cross_val_score(model, X, y, cv=5)
  print(f"{model} avg cross val score is {np.mean(score)}")
  model_df[model] = round(np.mean(score)*100,2)


# Logistic Regression
model = LogisticRegression()
model_value(model, X, y)

# Random Classifier
model = RandomForestClassifier()
model_value(model, X, y)


# Save Model
log_reg_grid={"C":np.logspace(-4,4,20),
             "solver":['liblinear']}
rs_log_reg=RandomizedSearchCV(LogisticRegression(),
                   param_distributions=log_reg_grid,
                  n_iter=20,cv=5,verbose=True)
rs_log_reg.fit(X,y)
rf = RandomForestClassifier(n_estimators=270,
 min_samples_split=5,
 min_samples_leaf=5,
 max_features='sqrt',
 max_depth=5)

rf.fit(X,y)


# Prediction
joblib.dump(rf,'loan_status_predict')
model = joblib.load('loan_status_predict')

df = pd.DataFrame({
    'Gender':0,
    'Married':0,
    'Dependents':0,
    'Education':0,
    'Self_Employed':0,
    'ApplicantIncome':1000,
    'CoapplicantIncome':1000000,
    'LoanAmount':100000.0,
    'Loan_Amount_Term':0,
    'Credit_History':2,
    'Property_Area':0
},index=[0])
result = model.predict(df)
if result==1:
    print("Loan Successfull")
else:
    print("Loan unsuccessfull")