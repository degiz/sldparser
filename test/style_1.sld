<?xml version="1.0" encoding="ISO-8859-1"?>
<!--
   Copyright 2011 David Zwarg <dzwarg@azavea.com>

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
-->
<StyledLayerDescriptor version="1.0.0" xmlns="http://www.opengis.net/sld" xmlns:ogc="http://www.opengis.net/ogc"
  xmlns:xlink="http://www.w3.org/1999/xlink" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
  xsi:schemaLocation="http://www.opengis.net/sld http://schemas.opengis.net/sld/1.0.0/StyledLayerDescriptor.xsd">
  <NamedLayer>
    <Name>poptot</Name>
    <UserStyle>
      <Title>Population</Title>
      <Abstract>A grayscale style showing the population numbers in a given geounit.</Abstract>
      <FeatureTypeStyle>
        <Rule>
          <Title>&gt;= 345 AND &lt; 880</Title>
          <ogc:Filter>
            <ogc:And>
              <ogc:PropertyIsLessThan>
                <ogc:PropertyName>number</ogc:PropertyName>
                <ogc:Literal>880</ogc:Literal>
              </ogc:PropertyIsLessThan>
              <ogc:PropertyIsGreaterThanOrEqualTo>
                <ogc:PropertyName>number</ogc:PropertyName>
                <ogc:Literal>345</ogc:Literal>
              </ogc:PropertyIsGreaterThanOrEqualTo>
            </ogc:And>
          </ogc:Filter>          
          <PolygonSymbolizer>
            <Fill>
              <CssParameter name="fill">#636363</CssParameter>
            </Fill>
          </PolygonSymbolizer>
        </Rule>
        <Rule>
          <Title>&gt; 345 AND &lt;= 880</Title>
          <ogc:Filter>
            <ogc:And>
              <ogc:PropertyIsGreaterThan>
                <ogc:PropertyName>number</ogc:PropertyName>
                <ogc:Literal>345</ogc:Literal>
              </ogc:PropertyIsGreaterThan>
              <ogc:PropertyIsLessThanOrEqualTo>
                <ogc:PropertyName>number</ogc:PropertyName>
                <ogc:Literal>880</ogc:Literal>
              </ogc:PropertyIsLessThanOrEqualTo>
            </ogc:And>
          </ogc:Filter>          
          <PolygonSymbolizer>
            <Fill>
              <CssParameter name="fill">#969696</CssParameter>
            </Fill>
          </PolygonSymbolizer>
        </Rule>
        <Rule>
          <Title>&lt; 345 OR &gt; 880</Title>
          <ogc:Filter>
            <ogc:Or>
              <ogc:PropertyIsLessThan>
                <ogc:PropertyName>number</ogc:PropertyName>
                <ogc:Literal>345</ogc:Literal>
              </ogc:PropertyIsLessThan>
              <ogc:PropertyIsGreaterThan>
                <ogc:PropertyName>number</ogc:PropertyName>
                <ogc:Literal>880</ogc:Literal>
              </ogc:PropertyIsGreaterThan>
            </ogc:Or>
          </ogc:Filter>          
          <PolygonSymbolizer>
            <Fill>
              <CssParameter name="fill">#CCCCCC</CssParameter>
            </Fill>
          </PolygonSymbolizer>
        </Rule>
        <Rule>
          <Title>= 345</Title>
          <ogc:Filter>
            <ogc:PropertyIsEqualTo>
              <ogc:PropertyName>number</ogc:PropertyName>
              <ogc:Literal>345</ogc:Literal>
            </ogc:PropertyIsEqualTo>
          </ogc:Filter>          
          <PolygonSymbolizer>
            <Fill>
              <CssParameter name="fill">#F7F7F7</CssParameter>
            </Fill>
          </PolygonSymbolizer>
        </Rule>
        <Rule>
          <Title>!= 345</Title>
          <ogc:Filter>
            <ogc:PropertyIsNotEqualTo>
              <ogc:PropertyName>number</ogc:PropertyName>
              <ogc:Literal>345</ogc:Literal>
            </ogc:PropertyIsNotEqualTo>
          </ogc:Filter> 
          <LineSymbolizer>
            <Stroke>
              <CssParameter name="stroke">#202020</CssParameter>
              <CssParameter name="stroke-width">0.50</CssParameter>
            </Stroke>
          </LineSymbolizer>
        </Rule>
        <Rule>
          <Title>!= 345</Title>
          <ogc:Filter>
            <ogc:Not>
              <ogc:PropertyIsEqualTo>
                <ogc:PropertyName>number</ogc:PropertyName>
                <ogc:Literal>345</ogc:Literal>
              </ogc:PropertyIsEqualTo>
            </ogc:Not>
          </ogc:Filter> 
          <LineSymbolizer>
            <Stroke>
              <CssParameter name="stroke">#202020</CssParameter>
              <CssParameter name="stroke-width">0.50</CssParameter>
            </Stroke>
          </LineSymbolizer>
        </Rule>
        <Rule>
          <Title>Complex</Title>
          <ogc:Filter>
            <ogc:And>
              <ogc:Not>
                <ogc:Or>
                  <ogc:PropertyIsLessThan>
                    <ogc:PropertyName>number</ogc:PropertyName>
                    <ogc:Literal>345</ogc:Literal>
                  </ogc:PropertyIsLessThan>
                  <ogc:PropertyIsGreaterThan>
                    <ogc:PropertyName>number</ogc:PropertyName>
                    <ogc:Literal>880</ogc:Literal>
                  </ogc:PropertyIsGreaterThan>
                </ogc:Or>
              </ogc:Not>
              <ogc:And>
                <ogc:PropertyIsGreaterThan>
                  <ogc:PropertyName>number</ogc:PropertyName>
                  <ogc:Literal>400</ogc:Literal>
                </ogc:PropertyIsGreaterThan>
                <ogc:PropertyIsLessThan>
                  <ogc:PropertyName>number</ogc:PropertyName>
                  <ogc:Literal>600</ogc:Literal>
                </ogc:PropertyIsLessThan>
              </ogc:And>
              <ogc:Or>
                <ogc:PropertyIsEqualTo>
                  <ogc:PropertyName>number</ogc:PropertyName>
                  <ogc:Literal>500</ogc:Literal>
                </ogc:PropertyIsEqualTo>
                <ogc:PropertyIsNotEqualTo>
                  <ogc:PropertyName>number</ogc:PropertyName>
                  <ogc:Literal>550</ogc:Literal>
                </ogc:PropertyIsNotEqualTo>
              </ogc:Or>
            </ogc:And>>
          </ogc:Filter> 
          <LineSymbolizer>
            <Stroke>
              <CssParameter name="stroke">#202020</CssParameter>
              <CssParameter name="stroke-width">0.50</CssParameter>
            </Stroke>
          </LineSymbolizer>
        </Rule>
        <Rule>
         <Title>Else</Title>
         <ogc:ElseFilter>
           <ogc:PropertyIsNotEqualTo>
             <ogc:PropertyName>number</ogc:PropertyName>
             <ogc:Literal>345</ogc:Literal>
           </ogc:PropertyIsNotEqualTo>
         </ogc:ElseFilter> 
         <LineSymbolizer>
           <Stroke>
             <CssParameter name="stroke">#202020</CssParameter>
             <CssParameter name="stroke-width">0.50</CssParameter>
           </Stroke>
         </LineSymbolizer>
        </Rule>
      </FeatureTypeStyle>
    </UserStyle>
  </NamedLayer>
</StyledLayerDescriptor>

